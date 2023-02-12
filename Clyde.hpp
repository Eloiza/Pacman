#ifndef CLYDE_HPP
#define CLYDE_HPP

#include "Ghost.hpp"
#include "ChaseRandom.hpp"
#include "Scatter.hpp"
#include "FrightenedBehavior.hpp"

class Clyde : public Ghost{
public:
    Clyde(Map *map, const Cell *pacmanPosition);
    void setCornerA(Cell *corner);
    void setCornerB(Cell *corner);

private:
    const Cell *pacmanPosition;
};

#endif