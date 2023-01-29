#ifndef GHOST_HPP
#define GHOST_HPP 

#include "Character.hpp"
#include <list>
#include <cmath>
#include <string> 
#include <set>
#include <queue>

#include "Node.hpp"
#include "Map.hpp"

class Ghost : public Character{
    public:
        /*constructors*/
        Ghost();
        Ghost(char sprite, unsigned char color_pair, unsigned char y, unsigned char x);

        double distance(Node p1, Node p2);
        double Ghost::distance(unsigned int x, unsigned int y, Node p2);

        void generateTarget(std::pair<unsigned char, unsigned char> pacman_position);
        Node generateDirection(Map * map, Node goal);
        std::priority_queue<Node, std::vector<Node>> Ghost::getNeighbors(Map *map, Node n, Node goal);

    protected:
        Node target;
        Node position;
};

#endif