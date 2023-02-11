#ifndef INKY_BEHAVIOR_HPP
#define INKY_BEHAVIOR_HPP

#include "Behavior.hpp"
#include <algorithm>

class InkyBehavior : public Behavior{
    public:
        /*Constructors*/
        InkyBehavior();
        InkyBehavior(Map *map, Cell *position, const Cell *pacmanPosition, const Cell* blinkyPosition);

        virtual ~InkyBehavior() = default;

        virtual const Cell *generateTarget();

        /*setters*/
        void setPacmanPosition(const Cell *pacmanPosition);
        void setBlinkyPosition(const Cell *blinkyPosition);

    private:
        const Cell * pacmanPosition; 
        const Cell * blinkyPosition;

};
#endif