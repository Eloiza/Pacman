#ifndef INKY_HPP
#define INKY_HPP

#include "Ghost.hpp"
#include "ChaseSiege.hpp"
#include "Scatter.hpp"
#include "FrightenedBehavior.hpp"

class Inky : public Ghost{
public:
    Inky(Map *map, const Cell *pacmanPosition, const Cell *pairGhost);
    void setCornerA(Cell *corner);
    void setCornerB(Cell *corner);

private:
    const Cell *pacmanPosition;
};

#endif