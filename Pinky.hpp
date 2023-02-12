#ifndef PINKY_HPP
#define PINKY_HPP

#include "Ghost.hpp"
#include "ChaseAmbush.hpp"
#include "Scatter.hpp"
#include "FrightenedBehavior.hpp"

class Pinky : public Ghost{
    public:
        Pinky(Map *map, const Cell *pacmanPosition);
        void setCornerA(Cell *corner);
        void setCornerB(Cell *corner);

    private:
        const Cell *pacmanPosition;
};

#endif