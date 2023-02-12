#ifndef BLINKY_HPP
#define BLINKY_HPP

#include "Ghost.hpp"
#include "ChaseAggresive.hpp"
#include "Scatter.hpp"
#include "FrightenedBehavior.hpp"

class Blinky : public Ghost{
    public:
        Blinky(Map *map, const Cell *pacmanPosition);
        void setCornerA(Cell *corner);
        void setCornerB(Cell *corner);

    private:
        const Cell * pacmanPosition;
};

#endif