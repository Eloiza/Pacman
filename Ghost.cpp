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

Ghost::Ghost(const Map *map, unsigned int row, unsigned int col) : Ghost(row, col){
    this->map = map;
};

Ghost::Ghost(const Map *map, unsigned int row, unsigned int col, const Cell * target) : Ghost(map, row, col){
    // this->setTarget(target);
};

// double Ghost::distance(const Cell *p1, const Cell *p2){
//     return abs(p2->row - p1->row) + abs(p2->col - p1->col);
// };

// double Ghost::distance(unsigned int row, unsigned int col, const Cell *p2){
//     return abs(p2->row - row) + abs(p2->col - col);
// };

/*setters*/
// void Ghost::setTarget(const Cell * const target){
//     // this->behavior.setTarget();

//     if (target->col < map->cols && 
//         target->row < map->rows && 
//         !this->isCollision(this->map, target)){
//             this->target = target;
//             this->setDirections(this->generatePath());
//         }
// };

void Ghost::setDirections(std::list<Cell *> directions){
    this->directions = directions;
};

/*getters*/
std::list<Cell *> Ghost::getDirections(){
    return this->directions;
};

// void Ghost::generateTarget(Cell *targetPosition){
//     // check state and select a new target. Can be cherries or pacman
//     this->target = targetPosition;
// };

// Cell * Ghost::generateDirection(){
//     if ((this->position.row == this->target->row && this->position.col == this->target->col) || this->directions.empty()){
//         return &this->position;
//         // generateTarget();
//         // generatePath();
//     }

//     Cell *ret = this->directions.front();
//     this->directions.pop_front();
//     return ret;
// }

// std::list<Cell*> Ghost::reconstructPath(Node * startNode, Node * lastNode){
//     std::list<Cell*> path;
//     Node * current = lastNode;
//     while(current->parent != nullptr){
//         path.push_front(current);
//         current = current->parent;
//     }

//     return path;
// };

// void printList(std::list<Node*> lista){
//     std::list<Node*>::iterator it = lista.begin();
//     for (; it != lista.end(); it++){
//         std::cout << "(" << (*it)->row << "," << (*it)->col << "): " << "f: " << (*it)->f << std::endl;
//     }
// }

// std::list<Cell*> Ghost::generatePath(){
//     // std::cout << "I am in generatePath\n";
//     std::list<Node*> openSet;
//     std::list<Node*> closeSet;
//     std::list<Node*> neighbors;

//     Node * start = new Node(this->position, 0, this->distance(&this->position, this->target));
//     start->parent = nullptr;
//     openSet.push_back(start);
//     // std::cout << "Start node" << start->row << "," << start->col << "\n";

//     Node * current;
//     double tentative_gScore;
//     std::list<Node*>::iterator nodeIt;
//     while(!openSet.empty()){
//         openSet.sort([](const Node* n1, const Node* n2)
//                      {return n1->f < n2->f;});
        
//         current = openSet.front();
//         // std::cout << "OPEN SET\n";
//         // printList(openSet);
//         // std::cout << "\n";
//         // std::cout << "CHECKING NODE" << current->row << "," << current->row << "\n";

//         if(current->row == this->target->row && current->col == this->target->col){
//             return this->reconstructPath(start, current);
//         }
//         openSet.pop_front(); //remove first node
//         closeSet.push_back(current);
//         neighbors = this->getNeighbors(current);
//         // std::cout << "I returned from getNeighbors\n";

//         for (nodeIt = neighbors.begin(); nodeIt != neighbors.end(); nodeIt++){
//             tentative_gScore = current->g + 1;

//             auto foundNodeOpenSet = std::find_if(openSet.begin(), openSet.end(), [&](Node const *cNode)
//                                                 {return cNode->row == (*nodeIt)->row && cNode->col == (*nodeIt)->col; });
            
//             auto foundNodeCloseSet = std::find_if(closeSet.begin(), closeSet.end(), [&](Node const *cNode)
//                                                   {return cNode->row == (*nodeIt)->row && cNode->col == (*nodeIt)->col; });

//             // if node not in openSet or closeSet
//             if (foundNodeOpenSet == openSet.end() && foundNodeCloseSet == closeSet.end()){
//                 // std::cout << "Adding node " << (*nodeIt)->row << "," << (*nodeIt)->col << " to openSet\n";
//                 (*nodeIt)->g = tentative_gScore;
//                 (*nodeIt)->f = tentative_gScore + this->distance(*nodeIt, target);
//                 (*nodeIt)->parent = current;
//                 openSet.push_back(*nodeIt);
//             }

//             else if (tentative_gScore < (*nodeIt)->g){
//                 (*nodeIt)->g = tentative_gScore;
//                 (*nodeIt)->f = tentative_gScore + this->distance(*nodeIt, target);
//                 (*nodeIt)->parent = current;
//             }
//         }
//     }

//     return std::list<Cell*>();
// }

// std::list<Node*> Ghost::getNeighbors(const Cell *n){
//     // std::cout << "I am in getNeighbors\n";

//     std::list<Node*> valid_neighbors;

//     // Define the possible x and y values of the neighbors
//     int dx[4] = {1, -1, 0, 0};
//     int dy[4] = {0, 0, 1, -1};

//     // Iterate over the possible x and y values
//     for (int i = 0; i < 4; i++){
//         int col = n->col + dx[i];
//         int row = n->row + dy[i];

//         // Check if the neighbor is within the boundaries of the map
//         if (col >= 0 && col < (int) map->cols && row >= 0 && row < (int) map->rows){
//             // Check if there is an obstacle at the location
//             if (!this->isCollision(map, row, col)){
//                 valid_neighbors.push_back(new Node(row, col, distance(row, col, this->target)));
//             }
//         }
//     }

//     return valid_neighbors;
// }

// void Ghost::move(){
//     Character::move(this->generateDirection());
// };
