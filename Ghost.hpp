#ifndef GHOST_HPP
#define GHOST_HPP 

#include <list>
#include "Colors.hpp"
#include "Character.hpp"

#include "Chase.hpp"
#include "Scatter.hpp"
#include "Behavior.hpp"
#include "FrightenedBehavior.hpp"

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
        void setActiveBehavior(Behavior * behavior);

        void setChaseBehavior(Chase * chase);
        void setScatterBehavior(Scatter * scatter);
        void setFrightenedBehavior(FrightenedBehavior * frightened);

        void activateChaseBehavior();
        void activateScatterBehavior();
        void activateFrightenedBehavior();

    protected:
        const Cell * target;
        std::list<Cell*> directions;
        const Map * map;
        Behavior * activeBehavior;
        Scatter * scatter;
        Chase * chase;
        FrightenedBehavior *frightened;
};

#endif