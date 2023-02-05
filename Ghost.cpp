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

Ghost::Ghost(unsigned int row, unsigned int col, ChaseBehavior *behavior): Ghost(row, col){
    this->setBehavior(behavior);
};

/*setters*/
void Ghost::setBehavior(ChaseBehavior *behavior){
    this->behavior = behavior;
};

void Ghost::setTarget(Cell * const target){
    this->behavior->setTarget(target);
    this->target = target;
};

void Ghost::move(){
    Character::move(this->behavior->generateDirection());
};

/*getters*/
