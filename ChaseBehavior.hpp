#ifndef CHASE_BEHAVIOR_HPP
#define CHASE_BEHAVIOR_HPP

#include "Behavior.hpp"
#include <iostream>

class ChaseBehavior : public Behavior{
    public:
        /*Constructors*/
        ChaseBehavior();
        ChaseBehavior(Map* map, Cell * position, Cell * pacmanPosition);

        virtual ~ChaseBehavior() = default;

        virtual Cell * generateTarget();

        /*setters*/
        void setPacmanPosition(Cell * pacmanPosition);

    private:
        Cell * pacmanPosition;
};

#endif