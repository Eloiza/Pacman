#include "Ghost.hpp"

using namespace gameColors;
/*constructors*/
Ghost::Ghost(){
};

Ghost::Ghost(char sprite, unsigned char color_pair, unsigned char y, unsigned char x)
: Character(sprite, color_pair, y, x){
};

Ghost::Ghost(unsigned int row, unsigned int col){
    this->setPosition(row, col);
    this->setPrevPosition(row, col);
    this->setSprite(MapElements::GHOST);
    this->setColor((unsigned int) Colors::GENERIC_GHOST);
};

/*implements euclidean distance*/
double Ghost::distance(const Cell *p1, const Cell *p2){
    return abs(p2->row - p1->row) + abs(p2->col - p1->col);
};

double Ghost::distance(unsigned int row, unsigned int col, const Cell *p2){
    return abs(p2->row - row) + abs(p2->col - col);
};

void Ghost::generateTarget(Cell * targetPosition){
    //check state and select a new target. Can be cherries or pacman 

    this->target = targetPosition;
};

void Ghost::setTarget(const Cell * const target){
    this->target = target;
};

Cell Ghost::generateDirection(){
    if (this->position.row == this->target->row && this->position.col == this->target->col){
        return this->position;
        // generateTarget();
        // generatePath();
    }
    if(this->directions.empty()){
        return this->position;
    }
    
    Cell * ret = this->directions.front();
    this->directions.pop_front();
    return *ret;
}

void Ghost::setDirections(std::list<Cell *> directions){
    this->directions = directions;
};

std::list<Cell*> Ghost::reconstructPath(Node * startNode, Node * lastNode){
    std::list<Cell*> path;
    Node * current = lastNode;
    while(current->row != startNode->row && current->col != startNode->col){
        path.push_front(current);
        current = current->parent;
    }

    return path;
};

std::list<Cell*> Ghost::generatePath(const Map *map, const Cell *goal){
    std::list<Node> openSet;
    std::list<Node> neighbors;

    Node start(this->position, 0, this->distance(&this->position, goal));
    openSet.push_back(start);

    Node current;
    double tentative_gScore;
    while(!openSet.empty()){
        openSet.sort();
        current = *openSet.begin();
        if(current.row == goal->row && current.col == goal->col){
            return this->reconstructPath(&start, &current);
        }
        neighbors = this->getNeighbors(map, &current, goal);
        for (auto n : neighbors){
            tentative_gScore = current.g + 1;

            auto foundNode = std::find_if(openSet.begin(), openSet.end(), [&] (Node const& cNode){
            return cNode.row == n.row && cNode.col == n.col;});

            //if node not in openSet
            if (foundNode == openSet.end()){
                openSet.push_back(n);
            }
            
            else if(tentative_gScore < n.g){
                n.g = tentative_gScore;
                n.f = tentative_gScore + this->distance(&n, goal);
                n.parent = &current;
            }
        }
    }

    return std::list<Cell*>();
}

std::list<Node> Ghost::getNeighbors(const Map *map, const Cell *n, const Cell *goal){
    std::list<Node> valid_neighbors;

    // Define the possible x and y values of the neighbors
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    // Iterate over the possible x and y values
    for (int i = 0; i < 4; i++){
        int col = n->col + dx[i];
        int row = n->row + dy[i];

        // Check if the neighbor is within the boundaries of the map
        if (col >= 0 && col < (int) map->cols && row >= 0 && row < (int) map->rows){
            // Check if there is an obstacle at the location
            if (!this->isCollision(map, row, col)){
                valid_neighbors.push_back(Node(row, col, distance(row, col, goal)));
            }
        }
    }

    return valid_neighbors;
}
