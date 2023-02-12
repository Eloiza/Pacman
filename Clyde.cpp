#include "Clyde.hpp"

using namespace gameColors;
using namespace behaviorsId;

Clyde::Clyde(Map *map, const Cell *pacmanPosition) : Ghost(map, 11, 16, (unsigned int)Colors::CLYDE){
    this->pacmanPosition = pacmanPosition;
    this->setCornerA(new Cell(23, 2));
    this->setCornerB(new Cell(21, 9));

    this->setChaseBehavior(new ChaseRandom(this->map, &this->position, this->pacmanPosition));
    this->setScatterBehavior(new Scatter(this->map, &this->position, this->cornerA, this->cornerB));
    this->setFrightenedBehavior(new FrightenedBehavior(this->map, &this->position));

    this->startInJail = 1;
    this->jailDuration = (ms)10000;
    this->activateInJailBehavior();
};

void Clyde::setCornerA(Cell *corner)
{
    this->cornerA = corner;
};

void Clyde::setCornerB(Cell *corner)
{
    this->cornerB = corner;
};