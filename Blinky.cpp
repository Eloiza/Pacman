#include "Blinky.hpp"

using namespace gameColors;

Blinky::Blinky(Map *map, const Cell * pacmanPosition) : Ghost(map, 9, 14, (unsigned int) Colors::BLINKY){
    this->pacmanPosition = pacmanPosition;
    this->setCornerA(new Cell (2,26));
    this->setCornerB(new Cell (5,21));

    this->setChaseBehavior(new ChaseAggresive(this->map, &this->position, this->pacmanPosition));
    this->setScatterBehavior(new Scatter(this->map, &this->position, this->cornerA, this->cornerB));
    this->setFrightenedBehavior(new FrightenedBehavior(this->map, &this->position));
    this->activateScatterBehavior();
    this->startInJail = 0;
};

void Blinky::setCornerA(Cell *corner){
    this->cornerA = corner;
};

void Blinky::setCornerB(Cell *corner){
    this->cornerB = corner;
};