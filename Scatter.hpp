#ifndef SCATTER_HPP
#define SCATTER_HPP

#include "Behavior.hpp"

class Scatter : public Behavior{
    public:
        Scatter(Map *map, Cell *position, Cell *cornerA, Cell *cornerB);

        virtual ~Scatter() = default;
        virtual void setCornersPosition(const Cell *cornerA, const Cell *cornerB);
        const Cell * generateTarget();

        const Cell * getCornerA();
        const Cell * getCornerB();

    protected:
        const Cell * cornerA;
        const Cell * cornerB;
};

#endif