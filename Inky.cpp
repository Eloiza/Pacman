#include "Inky.hpp"

using namespace gameColors;
using namespace behaviorsId;

Inky::Inky(Map *map, const Cell *pacmanPosition, const Cell *pairGhost) : Ghost(map, 11, 13, (unsigned int)Colors::INKY)
{
    this->pacmanPosition = pacmanPosition;
    this->setCornerA(new Cell(21, 17));
    this->setCornerB(new Cell(23, 26));

    this->setChaseBehavior(new ChaseSiege(this->map, &this->position, this->pacmanPosition, pairGhost));
    this->setScatterBehavior(new Scatter(this->map, &this->position, this->cornerA, this->cornerB));
    this->setFrightenedBehavior(new FrightenedBehavior(this->map, &this->position));

    this->startInJail = 1;
    this->jailDuration = (ms)4000;
    this->activateInJailBehavior();
};

void Inky::setCornerA(Cell *corner){
    this->cornerA = corner;
};

void Inky::setCornerB(Cell *corner){
    this->cornerB = corner;
};