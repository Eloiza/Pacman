#include "Character.hpp"

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
    if(!collision(y, x)){
        this->y = y;
        this->x = x;
    }
};
