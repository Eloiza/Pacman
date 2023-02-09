#ifndef SCATTER_BEHAVIOR_HPP
#define SCATTER_BEHAVIOR_HPP

#include "Behavior.hpp"

class ScatterBehavior : public Behavior{
    public:
        ScatterBehavior();
        ScatterBehavior(Map *map, Cell *position, Cell *cornerA, Cell *cornerB);

        virtual ~ScatterBehavior() = default;

        virtual const Cell * generateTarget();

    private:
        Cell * cornerA;
        Cell * cornerB;
};

#endif