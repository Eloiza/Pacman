#include "Character.hpp"

Character::Character(){
};
Character::Character(char sprite, unsigned char color_pair, unsigned char y, unsigned char x)
    :sprite{sprite}, color_pair{color_pair}{
    this->set_position(y, x);
};

Character::Character(char sprite, unsigned char y, unsigned char x)
    :sprite{sprite}{
    this->set_position(y, x);
};

Character::Character(char sprite):sprite{sprite}{
    this->set_position(0,0);
};


void Character::move(unsigned char direction){
    switch (direction){
    case 'a':
        this->set_position(this->y, this->x-1); 
        break;
    case 'd':
        this->set_position(this->y, this->x+1); 
        break;
    case 'w':
        this->set_position(this->y-1, this->x); 
        break;
    case 's':
        this->set_position(this->y+1, this->x); 
        break;
    };
};

bool Character::collision(unsigned char y, unsigned char x){
    int testch;
    testch = mvinch(y, x);
    return (((testch & A_CHARTEXT) == '_') || ((testch & A_CHARTEXT) == '|'));
};

void Character::set_position(unsigned char y, unsigned char x){
    if(!this->collision(y, x)){
        this->y = y;
        this->x = x;
    }
};

void Character::set_x(unsigned x){
    if(!this->collision(this->y, x)){
        this->x = x;
    }
};

void Character::set_y(unsigned x){
    if (!this->collision(this->y, x)){
        this->x = x;
    }
};