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
#include "Behavior.hpp"

class Ghost : public Character{
    public:
        /*constructors*/
        Ghost();
        Ghost(char sprite, unsigned char color_pair, unsigned char row, unsigned char col);
        Ghost(unsigned int row, unsigned int col);
        Ghost(const Map *map, unsigned int row, unsigned int col);
        Ghost(const Map *map, unsigned int row, unsigned int col, Cell * target);
        Ghost(unsigned int row, unsigned int col, Behavior * behavior);

        virtual ~Ghost() = default;

        void move();

        /*setters*/
        void setTarget(Cell * const target);
        void setBehavior(Behavior * behavior);

        /*getters*/
    
    protected:
        const Cell * target;
        std::list<Cell*> directions;
        const Map * map;
        Behavior * behavior;
};

#endif