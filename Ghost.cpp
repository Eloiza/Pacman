#include "Ghost.hpp"

using namespace gameColors;
using namespace behaviorsId;

/*constructors*/
Ghost::Ghost(unsigned int row, unsigned int col){
    this->startPosition = new Cell(11, 15);
    this->setPosition(row, col);
    this->setPrevPosition(row, col);
    this->setSprite(MapElements::GHOST);
    this->setColor((unsigned int) Colors::GENERIC_GHOST);
    this->defaultColor = (unsigned int) Colors::GENERIC_GHOST;
};

Ghost::Ghost(const Map *map, unsigned int row, unsigned int col, Chase *chaseBh, Scatter *scatterBh, FrightenedBehavior * frightenedBh) : Ghost(row, col){
    this->map = map;
    this->chaseDuration = (ms) 8000;
    this->scatterDuration = (ms) 2000;
    this->deadDuration = (ms) 8000;
    this->frightenedDuration = (ms) 1000;

    this->setChaseBehavior(chaseBh);
    this->setScatterBehavior(scatterBh);
    this->setFrightenedBehavior(frightenedBh);
    this->activateChaseBehavior();

    this->behaviorClock = Clock();
};

/*setters*/
void Ghost::move(bool pacmanInvencible){
    Character::move(this->activeBehavior->getNextPosition());
    if (this->isCollision(&this->position, (char)MapElements::PACMAN) && this->curBehaviorId == (short int) GhostBehaviorId::FRIGHTENED){
        this->activateRetreatBehavior();
    }
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
    this->chase->setPosition(&this->position);
    this->chase->setTarget(this->chase->generateTarget());
    this->setActiveBehavior(this->chase);
};

void Ghost::activateScatterBehavior(){
    this->curBehaviorId = (short int) GhostBehaviorId::SCATTER;
    this->scatter->setPosition(&this->position);
    this->scatter->setTarget(this->scatter->generateTarget());
    this->setActiveBehavior(this->scatter);
};

void Ghost::activateRetreatBehavior(){
    this->curBehaviorId = (short int)GhostBehaviorId::RETREAT;

    this->activeBehavior->setPosition(&this->position);
    this->activeBehavior->setTarget(this->startPosition);
    this->setColor((unsigned int) Colors::DEFAULT);
};

void Ghost::deactivateRetreatBehavior(){
    this->setColor((unsigned int) this->defaultColor);
};

void Ghost::activateFrightenedBehavior(){
    this->curBehaviorId = (short int) GhostBehaviorId::FRIGHTENED;
    this->frightened->setPosition(&this->position);
    this->frightened->setTarget(this->frightened->generateTarget());
    this->setActiveBehavior(this->frightened);

    this->setColor((unsigned int) Colors::FRIGHTENED_GHOST);
};

void Ghost::deactivateFrightenedBehavior(){
    this->setColor(this->defaultColor);
};

void Ghost::updateBehavior(bool pacmanInvencible){
    ms duration = this->behaviorClock.end();
    if(!pacmanInvencible){
        this->enableFrightened = 1;
    }
    /*transition chase->scatter*/
    if(this->curBehaviorId == (short int)GhostBehaviorId::CHASE && duration > this->chaseDuration){
        this->activateScatterBehavior();
        this->behaviorClock.start();
    }

    /*transition scatter->chase*/
    else if(this->curBehaviorId == (short int)GhostBehaviorId::SCATTER && duration > this->scatterDuration){
        this->activateChaseBehavior();
        this->behaviorClock.start();
    }

    /*transition frightened->scatter*/
    else if(this->curBehaviorId == (short int)GhostBehaviorId::FRIGHTENED && duration > this->frightenedDuration){
        this->activateScatterBehavior();
        this->deactivateFrightenedBehavior();
        this->behaviorClock.start();
    }

    /*transition any->frightened*/
    else if (this->curBehaviorId != (short int)GhostBehaviorId::FRIGHTENED && 
            (this->curBehaviorId != (short int)GhostBehaviorId::RETREAT) && 
            pacmanInvencible &&
            this->enableFrightened){
        this->activateFrightenedBehavior();
        this->behaviorClock.start();
    }

    else if (this->curBehaviorId == (short int)GhostBehaviorId::RETREAT){
        if(this->position == *this->startPosition){
            this->deactivateRetreatBehavior();
            this->activateScatterBehavior();
            this->enableFrightened = 0;
        }
    }
};

void Ghost::startClock(){
    this->behaviorClock.start();
};
