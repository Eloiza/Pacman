#ifndef GHOST_HPP
#define GHOST_HPP 

#include <list>
#include <cmath>
#include <string> 
#include <iostream>
#include <algorithm>

#include "Map.hpp"
#include "Node.hpp"
#include "Cell.hpp"
#include "Colors.hpp"
#include "Character.hpp"
#include "MapElements.hpp"

class Ghost : public Character{
    public:
        /*constructors*/
        Ghost();
        Ghost(char sprite, unsigned char color_pair, unsigned char row, unsigned char col);
        Ghost(unsigned int row, unsigned int col);
        Ghost(const Map *map, unsigned int row, unsigned int col);

        /*manhathan distance*/
        double distance(const Cell *p1, const Cell *p2);
        double distance(unsigned int x, unsigned int y, const Cell *p2);

        void generateTarget(Cell * targetPosition);
        std::list<Cell*> reconstructPath(Node * startNode, Node * lastNode);
        std::list<Cell*> generatePath();
        std::list<Node *> getNeighbors(const Cell *n);
        Cell generateDirection();


        /*setters*/
        void setTarget(const Cell * const target);
        void setDirections(std::list<Cell *> directions);

        /*getters*/
        std::list<Cell*> getDirections();
    
    protected:
        const Cell * target;
        std::list<Cell*> directions;
        const Map * map;
};

#endif