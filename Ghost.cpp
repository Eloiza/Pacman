#include "Ghost.hpp"

using namespace gameColors;
using namespace behaviorsId;

/*constructors*/
Ghost::Ghost(unsigned int row, unsigned int col){
    this->setPosition(row, col);
    this->setPrevPosition(row, col);
    this->setSprite(MapElements::GHOST);
    this->setColor((unsigned int) Colors::GENERIC_GHOST);
};

Ghost::Ghost(const Map *map, unsigned int row, unsigned int col, Chase *chaseBh, Scatter *scatterBh, FrightenedBehavior * frightenedBh) : Ghost(row, col){
    this->map = map;
    this->behaviorClock = Clock();
    this->chaseDuration = (std::chrono::duration<double, std::milli>)20000.;
    this->scatterDuration = (std::chrono::duration<double, std::milli>)7000.0;
    this->deadDuration = (std::chrono::duration<double, std::milli>)8000.0;
    this->frightenedDuration = (std::chrono::duration<double, std::milli>)8000.0;

    this->setChaseBehavior(chaseBh);
    this->setScatterBehavior(scatterBh);
    this->setFrightenedBehavior(frightenedBh);
    this->activateChaseBehavior();
};

/*setters*/
void Ghost::move(){
    Character::move(this->activeBehavior->getNextPosition());
};

void Ghost::setTarget(Cell *const target){
    this->activeBehavior->setTarget(target);
};

void Ghost::setActiveBehavior(Behavior *behavior){
    this->activeBehavior = behavior;
};

void Ghost::setChaseBehavior(Chase *chase){
    this->chase = chase;
};

void Ghost::setScatterBehavior(Scatter *scatter){
    this->scatter = scatter;
};

void Ghost::setFrightenedBehavior(FrightenedBehavior *frightened){
    this->frightened = frightened;
};

void Ghost::activateChaseBehavior(){
    this->curBehaviorId = (short int)GhostBehaviorId::CHASE;
    this->setActiveBehavior(this->chase);
};

void Ghost::activateScatterBehavior(){
    this->curBehaviorId = (short int) GhostBehaviorId::SCATTER;
    this->setActiveBehavior(this->scatter);
};

void Ghost::activateFrightenedBehavior(){
    this->curBehaviorId = (short int) GhostBehaviorId::FRIGHTENED;
    this->setActiveBehavior(this->frightened);
};

void Ghost::updateBehavior(){
    using ms = std::chrono::duration<double, std::milli>;

    ms duration = this->behaviorClock.end();
    /*transition chase->scatter*/
    if(this->curBehaviorId == (short int)GhostBehaviorId::CHASE && (ms) duration > this->chaseDuration)
        this->activateScatterBehavior();

    /*transition scatter->chase*/
    else if(this->curBehaviorId == (short int)GhostBehaviorId::SCATTER && (ms)duration > this->scatterDuration)
        this->activateChaseBehavior();

    /*transition dead->scatter*/
    else if(this->curBehaviorId == (short int)GhostBehaviorId::DEAD && (ms)duration > this->deadDuration)
        this->activateScatterBehavior();

    /*transition frightened->scatter*/
    else if(this->curBehaviorId == (short int)GhostBehaviorId::FRIGHTENED && (ms)duration > this->frightenedDuration)
        this->activateScatterBehavior();

    this->behaviorClock.start();
};
