#include "Ghost.hpp"

using namespace gameColors;
/*constructors*/
Ghost::Ghost(){
};

Ghost::Ghost(char sprite, unsigned char color_pair, unsigned char y, unsigned char x)
: Character(sprite, color_pair, y, x){
};

Ghost::Ghost(unsigned int row, unsigned int col){
    this->setPosition(row, col);
    this->setPrevPosition(row, col);
    this->setSprite(MapElements::GHOST);
    this->setColor((unsigned int) Colors::GENERIC_GHOST);
};

Ghost::Ghost(const Map *map, unsigned int row, unsigned int col) : Ghost(row, col){
    this->map = map;
};

Ghost::Ghost(const Map *map, unsigned int row, unsigned int col, Cell * target) : Ghost(map, row, col){
    this->setTarget(target);
};

Ghost::Ghost(unsigned int row, unsigned int col, Behavior *behavior): Ghost(row, col){
    this->setActiveBehavior(behavior);
};

/*setters*/
void Ghost::move(){
    Character::move(this->activeBehavior->getNextPosition());
};

void Ghost::setTarget(Cell *const target){
    this->activeBehavior->setTarget(target);
    this->target = target;
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
    this->setActiveBehavior(this->chase);
};

void Ghost::activateScatterBehavior(){
    this->setActiveBehavior(this->scatter);
};

void Ghost::activateFrightenedBehavior(){
    this->setActiveBehavior(this->frightened);
};

