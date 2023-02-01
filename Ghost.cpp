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
double Ghost::distance(Cell * p1, Cell * p2){
    return abs(p2->row - p1->row) + abs(p2->col - p1->col);
};

double Ghost::distance(unsigned int row, unsigned int col, Cell * p2){
    return abs(p2->row - row) + abs(p2->col - col);
};

// void Ghost::generateTarget(std::pair<unsigned char, unsigned char> pacman_position){
//     this->target = pacman_position;
// };

void Ghost::setTarget(Cell * const target){
    this->target = target;
};

Cell Ghost::getDirection(){
    if()
}

std::list<Cell*> reconstructPath(Node * startNode, Node * lastNode){
    std::list<Cell*> path;
    Node * current = lastNode;
    while(current->row != startNode->row && current->col != startNode->col){
        path.push_front(current);
        current = current->parent;
    }

    return path;
};

std::list<Cell*> Ghost::generatePath(Map *map, Cell * goal){
    if(this->position.row == goal->row && this->position.col == goal->col){
        return std::list<Cell*>();
    }

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

std::list<Node> Ghost::getNeighbors(Map *map, Cell * n, Cell * goal){
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
            if (!isCollision(map, row, col)){
                valid_neighbors.push_back(Node(row, col, distance(row, col, goal)));
            }
        }
    }

    return valid_neighbors;
}
