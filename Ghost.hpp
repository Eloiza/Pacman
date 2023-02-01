#ifndef GHOST_HPP
#define GHOST_HPP 

#include "Character.hpp"
#include <list>
#include <cmath>
#include <string> 
#include <set>
#include <queue>
#include <iostream>
#include <algorithm>
#include "Node.hpp"
#include "Map.hpp"
#include "Cell.hpp"
#include "MapElements.hpp"
#include "Colors.hpp"

class Ghost : public Character{
    public:
        /*constructors*/
        Ghost();
        Ghost(char sprite, unsigned char color_pair, unsigned char row, unsigned char col);
        Ghost(unsigned int row, unsigned int col);

        double distance(const Cell *p1, const Cell *p2);
        double distance(unsigned int x, unsigned int y, const Cell *p2);
        void generateTarget(Cell * targetPosition);
        std::list<Cell*> reconstructPath(Node * startNode, Node * lastNode);
        std::list<Cell *> generatePath(const Map *map, const Cell *goal);
        Cell generateDirection();

        std::list<Node*> getNeighbors(const Map *map, const Cell *n, const Cell *goal);

        /*setters*/
        void setTarget(const Cell * const target);
        void setDirections(std::list<Cell *> directions);

        /*getters*/
        std::list<Cell*> getDirections();
    protected:
        const Cell * target;
        std::list<Cell*> directions;
};

#endif