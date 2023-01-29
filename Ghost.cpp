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

/*implements manhathan distance*/
double Ghost::distance(Cell p1, Cell p2){
    return abs(p2.row - p1.row) + abs(p2.col - p1.col);
};

double Ghost::distance(unsigned int row, unsigned int col, Cell p2){
    return abs(p2.row - row) + abs(p2.col - col);
};

// void Ghost::generateTarget(std::pair<unsigned char, unsigned char> pacman_position){
//     this->target = pacman_position;
// };

void Ghost::setTarget(Cell * const target){
    this->target = *target;
};

Cell Ghost::generateDirection(Map *map, Cell goal){
    // Node nodePosition = Node(this->x, this->y, 0);
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> neighbors;
    neighbors = this->getNeighbors(map, this->position, goal);
    

    if(neighbors.size() == 0){
        return this->position;
    }

    Node best = neighbors.top();
    while (!neighbors.empty()){
        std::cout << neighbors.top().f << "\n";
        neighbors.pop();
    }

    return best;
}

std::priority_queue<Node, std::vector<Node>, std::greater<Node>> Ghost::getNeighbors(Map *map, Cell n, Cell goal){
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> valid_neighbors;

    // Define the possible x and y values of the neighbors
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    // Iterate over the possible x and y values
    for (int i = 0; i < 4; i++){
        int col = n.col + dx[i];
        int row = n.row + dy[i];

        // Check if the neighbor is within the boundaries of the map
        if (col >= 0 && col < (int) map->cols && row >= 0 && row < (int) map->rows){
            // Check if there is an obstacle at the location
            if (!isCollision(map, row, col)){
                valid_neighbors.push(Node(col, row, distance(col, row, goal)));
            }
        }
    }

    return valid_neighbors;
}
