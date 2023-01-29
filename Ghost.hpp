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

class Ghost : public Character{
    public:
        /*constructors*/
        Ghost();
        Ghost(char sprite, unsigned char color_pair, unsigned char y, unsigned char x);
        Ghost(Node position);

        bool collision_new(Map *map, unsigned char y, unsigned char x);

        double distance(Node p1, Node p2);
        double distance(unsigned int x, unsigned int y, Node p2);
        virtual void move(Node newPosition);

        void generateTarget(std::pair<unsigned char, unsigned char> pacman_position);
        Node generateDirection(Map * map, Node goal);
        std::priority_queue<Node, std::vector<Node>, std::greater<Node>> getNeighbors(Map *map, Node n, Node goal);

        /*setters*/
        void setPosition(Node position);
        void setTarget(Node target);

    // protected:
        Node previousPosition;
        Node target;
        Node position;
};

#endif