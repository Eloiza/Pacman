#ifndef SCATTER_HPP
#define SCATTER_HPP

#include "Behavior.hpp"

class Scatter : public Behavior{
    public:
        Scatter(const Map *map, Cell *position, const Cell *cornerA, const Cell *cornerB);

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