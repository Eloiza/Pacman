#include "Character.hpp"

/*constructors*/
Character::Character(){
};

Character::Character(char sprite, unsigned int color, unsigned int row, unsigned int col)
    :sprite{sprite}, color{color}{
    this->setPosition(row, col);
};

Character::Character(char sprite, unsigned int row, unsigned int col)
    :sprite{sprite}{
    this->setPosition(row, col);
};

void Character::move(unsigned int direction){
    switch (direction){
    case 'a':
        this->setPrevPosition(this->position.row, this->position.col);
        this->setPosition(this->position.row, this->position.col-1); 
        break;
    case 'd':
        this->setPrevPosition(this->position.row, this->position.col);
        this->setPosition(this->position.row, this->position.col+1); 
        break;
    case 'w':
        this->setPrevPosition(this->position.row, this->position.col);
        this->setPosition(this->position.row-1, this->position.col); 
        break;
    case 's':
        this->setPrevPosition(this->position.row, this->position.col);
        this->setPosition(this->position.row+1, this->position.col); 
        break;
    };
};

void Character::move(Cell * const new_position){
    this->setPrevPosition(&this->position);
    this->setPosition(new_position);
};

bool Character::isCollision(unsigned int row, unsigned int col){
    int testch;
    testch = mvinch(row, col);
    return (((testch & A_CHARTEXT) == MapElements::WALL));
};

bool Character::isCollision(Cell * const position){
    int testch;
    testch = mvinch(position->row, position->col);
    return (((testch & A_CHARTEXT) == MapElements::WALL));
};

bool Character::isCollision(const Map *map, unsigned int row, unsigned int col){
    if(row >= map->rows || col >= map->cols )
        return 1;

    return map->map[row*map->cols+col] == MapElements::WALL;
};

bool Character::isCollision(const Map *map, const Cell* const position){
    if (position->row >= map->rows || position->col >= map->cols)
        return 1;
        
    return map->map[position->row * map->cols + position->col] == MapElements::WALL;
};

/*setters*/
void Character::setPrevPosition(unsigned int row, unsigned int col){
    this->prevPosition.row = row;
    this->prevPosition.col = col;
};

void Character::setPrevPosition(Cell * const position){
    this->prevPosition = *position;
};

void Character::setPrevCol(unsigned int prev_col){
    this->prevPosition.col = prev_col;
};

void Character::setPrevRow(unsigned int prev_row){
    this->prevPosition.row = prev_row;
};

void Character::setPosition(unsigned int row, unsigned int col){
    if(!this->isCollision(row, col)){
        this->position.row = row;
        this->position.col = col;
    }
};

void Character::setPosition(Cell * position){
    this->position = *position;
};

void Character::setCol(unsigned int col){
    if(!this->isCollision(this->position.row, col)){
        this->position.col = col;
    }
};

void Character::setRow(unsigned int row){
    if (!this->isCollision(row, this->position.col)){
        this->position.row = row;
    }
};

void Character::setSprite(unsigned int sprite){
    this->sprite = sprite;
};

void Character::setColor(unsigned int color){
    this->color = color;
};

/*getters*/
const Cell *Character::getPosition(){
    return &this->position;
};

const Cell *Character::getPrevPosition(){
    return &this->prevPosition;
};

char Character::getSprite(){
    return this->sprite;
};

unsigned int Character::getColor(){
    return this->color;
};

unsigned int Character::getCol(){
    return this->position.col;
};

unsigned int Character::getRow(){
    return this->position.row;
};

unsigned int Character::getPrevCol(){
    return this->prevPosition.col;
};

unsigned int Character::getPrevRow(){
    return this->prevPosition.row;
};

