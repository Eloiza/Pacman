#ifndef CHASE_BEHAVIOR_HPP
#define CHASE_BEHAVIOR_HPP

#include "Behavior.hpp"
#include <iostream>

class ChaseBehavior : public Behavior{
    public:
        /*Constructors*/
        ChaseBehavior();
        ChaseBehavior(Map* map, Cell * position, const Cell * pacmanPosition);

        virtual ~ChaseBehavior() = default;

        virtual const Cell * generateTarget();

        /*setters*/
        void setPacmanPosition(const Cell * pacmanPosition);

    private:
        const Cell * pacmanPosition;
};

#endif