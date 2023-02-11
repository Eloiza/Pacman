#ifndef CHASE_HPP
#define CHASE_HPP

#include "Behavior.hpp"

class Chase : public Behavior{
    public:
        virtual ~Chase() = default;
        virtual void setPacmanPosition(const Cell * pacmanPosition) = 0;

    protected:
        const Cell * pacmanPosition;
};

#endif