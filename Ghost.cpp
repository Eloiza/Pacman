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
    this->chaseDuration = 0.001000;
    this->scatterDuration = 0.001000;
    this->deadDuration = 8000.0;
    this->frightenedDuration = 8000.0;

    this->setChaseBehavior(chaseBh);
    this->setScatterBehavior(scatterBh);
    this->setFrightenedBehavior(frightenedBh);
    this->activateChaseBehavior();

    this->behaviorClock = Clock();
    this->behaviorClock.start();
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
    if(this->curBehaviorId == (short int)GhostBehaviorId::CHASE && duration.count() > this->chaseDuration){
        this->activateScatterBehavior();
        this->behaviorClock.start();
    }

    /*transition scatter->chase*/
    else if(this->curBehaviorId == (short int)GhostBehaviorId::SCATTER && duration.count() > this->scatterDuration){
        this->activateChaseBehavior();
        this->behaviorClock.start();
    }

    /*transition dead->scatter*/
    else if(this->curBehaviorId == (short int)GhostBehaviorId::DEAD && duration.count() > this->deadDuration){
        this->activateScatterBehavior();
        this->behaviorClock.start();
    }

    /*transition frightened->scatter*/
    else if(this->curBehaviorId == (short int)GhostBehaviorId::FRIGHTENED && duration.count() > this->frightenedDuration){
        this->activateScatterBehavior();
        this->behaviorClock.start();
    }

};
