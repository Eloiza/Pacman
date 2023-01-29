#ifndef GHOST_HPP
#define GHOST_HPP 

#include "Character.hpp"
#include <list>
#include <cmath>
#include <string> 
#include <set>
#include <queue>
#include <iostream>

#include "Node.hpp"
#include "Map.hpp"
#include "Cell.hpp"

class Ghost : public Character{
    public:
        /*constructors*/
        Ghost();
        Ghost(char sprite, unsigned char color_pair, unsigned char row, unsigned char col);
        Ghost(unsigned int row, unsigned int col);

        double distance(Cell p1, Cell p2);
        double distance(unsigned int x, unsigned int y, Cell p2);

        // void generateTarget(std::pair<unsigned char, unsigned char> pacman_position);
        Cell generateDirection(Map *map, Cell goal);

        std::priority_queue<Node, std::vector<Node>, std::greater<Node>> Ghost::getNeighbors(Map *map, Cell n, Cell goal);

        /*setters*/
        void setTarget(Cell * const target);

    protected:
        Cell target;
};

#endif