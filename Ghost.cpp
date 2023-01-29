#include "Ghost.hpp"

/*constructors*/
Ghost::Ghost(){
};
Ghost::Ghost(char sprite, unsigned char color_pair, unsigned char y, unsigned char x)
: Character(sprite, color_pair, y, x){
};

/*implements manhathan distance*/
double Ghost::distance(Node p1, Node p2){
    return abs(p2.x - p1.x) + abs(p2.y - p1.y);
};

double Ghost::distance(unsigned int x, unsigned int y, Node p2){
    return abs(p2.x - x) + abs(p2.y - y);
};

void Ghost::generateTarget(std::pair<unsigned char, unsigned char> pacman_position){
    this->target = pacman_position;
};

Node Ghost::generateDirection(Map *map, Node goal){
    Node nodePosition = Node(this->x, this->y, 0);
    std::priority_queue<Node, std::vector<Node>, std::less<Node>> neighbors = this->getNeighbors(map, this->position, goal);

    return neighbors.top();
}

std::priority_queue<Node, std::vector<Node>> Ghost::getNeighbors(Map *map, Node n, Node goal){
    std::priority_queue<Node, std::vector<Node>, std::less<Node>> valid_neighbors;

    // Define the possible x and y values of the neighbors
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    // Iterate over the possible x and y values
    for (int i = 0; i < 4; i++){
        int x = n.x + dx[i];
        int y = n.y + dy[i];

        // Check if the neighbor is within the boundaries of the map
        if (x >= 0 && x < map->cols && y >= 0 && y < map->rows){
            // Check if there is an obstacle at the location
            if (!collision(y, x)){
                valid_neighbors.push(Node(x, y, distance(x, y, goal)));
            }
        }
    }

    return valid_neighbors;
}
