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

/*setters*/
void Ghost::setTarget(const Cell * const target){
    this->target = target;
};

void Ghost::setDirections(std::list<Cell *> directions){
    this->directions = directions;
};

/*getters*/
std::list<Cell *> Ghost::getDirections(){
    return this->directions;
};

void Ghost::generateTarget(Cell *targetPosition){
    // check state and select a new target. Can be cherries or pacman
    this->target = targetPosition;
};

Cell Ghost::generateDirection(){
    if (this->position.row == this->target->row && this->position.col == this->target->col){
        return this->position;
        // generateTarget();
        // generatePath();
    }
    if (this->directions.empty()){
        return this->position;
    }

    Cell *ret = this->directions.front();
    this->directions.pop_front();
    return *ret;
}

std::list<Cell*> Ghost::reconstructPath(Node * startNode, Node * lastNode){
    std::cout << "I am in reconstructPath\n";

    std::list<Cell*> path;
    Node * current = lastNode;
    while(current->row != startNode->row && current->col != startNode->col){
        path.push_front(current);
        current = current->parent;
    }

    return path;
};

void printList(std::list<Node*> lista){
    std::list<Node*>::iterator it = lista.begin();
    for (; it != lista.end(); it++){
        std::cout << "(" << (*it)->row << "," << (*it)->col << ")" << std::endl;
    }
}

std::list<Cell*> Ghost::generatePath(const Map *map, const Cell *goal){
    std::cout << "I am in generatePath\n";
    std::list<Node*> openSet;
    std::list<Node*> neighbors;

    Node * start = new Node(this->position, 0, this->distance(&this->position, goal));
    openSet.push_back(start);

    Node * current;
    double tentative_gScore;
    std::list<Node*>::iterator nodeIt;
    while(!openSet.empty()){
        std::cout << "OPEN SET\n";
        printList(openSet);
        std::cout << "\n";

        openSet.sort();
        current = openSet.front();
        if(current->row == goal->row && current->col == goal->col){
            return this->reconstructPath(start, current);
        }
        openSet.pop_front(); //remove first node
        neighbors = this->getNeighbors(map, current, goal);
        std::cout << "I returned from getNeighbors\n";


        for(nodeIt=neighbors.begin(); nodeIt != neighbors.end(); nodeIt++){
            tentative_gScore = current->g + 1;

            auto foundNode = std::find_if(openSet.begin(), openSet.end(), [&](Node const *cNode)
                                          {return cNode->row == (*nodeIt)->row && cNode->col == (*nodeIt)->col; });

            // if node not in openSet
            if (foundNode == openSet.end()){
                openSet.push_back(*nodeIt);
            }

            else if (tentative_gScore < (*nodeIt)->g){
                (*nodeIt)->g = tentative_gScore;
                (*nodeIt)->f = tentative_gScore + this->distance(*nodeIt, goal);
                (*nodeIt)->parent = current;
            }
        }
        
    }

    return std::list<Cell*>();
}

std::list<Node*> Ghost::getNeighbors(const Map *map, const Cell *n, const Cell *goal){
    std::cout << "I am in getNeighbors\n";

    std::list<Node*> valid_neighbors;

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
                valid_neighbors.push_back(new Node(row, col, distance(row, col, goal)));
            }
        }
    }

    return valid_neighbors;
}
