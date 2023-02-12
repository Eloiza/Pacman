#include "Pinky.hpp"

using namespace gameColors;
using namespace behaviorsId;

Pinky::Pinky(Map *map, const Cell *pacmanPosition) : Ghost(map, 11, 14, (unsigned int)Colors::PINKY){
    this->pacmanPosition = pacmanPosition;
    this->setCornerA(new Cell(2, 1));
    this->setCornerB(new Cell(5, 6));

    this->setChaseBehavior(new ChaseAmbush(this->map, &this->position, this->pacmanPosition, 4));
    this->setScatterBehavior(new Scatter(this->map, &this->position, this->cornerA, this->cornerB));
    this->setFrightenedBehavior(new FrightenedBehavior(this->map, &this->position));

    this->startInJail = 1;
    this->jailDuration = (ms)2000;
    this->activateInJailBehavior();
};

void Pinky::setCornerA(Cell *corner)
{
    this->cornerA = corner;
};

void Pinky::setCornerB(Cell *corner){
    this->cornerB = corner;
};