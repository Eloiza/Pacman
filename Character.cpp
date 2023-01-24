#include "Character.hpp"

/*constructors*/
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

/*setters*/
void Character::set_position(unsigned char y, unsigned char x){
    if(!this->collision(y, x)){
        this->y = y;
        this->x = x;
    }
};

void Character::set_x(unsigned char x){
    if(!this->collision(this->y, x)){
        this->x = x;
    }
};

void Character::set_y(unsigned char y){
    if (!this->collision(y, this->x)){
        this->y = y;
    }
};

void Character::set_state(bool state){
    this->state = state;
};

void Character::set_sprite(unsigned char sprite){
    this->sprite = sprite;
};

void Character::set_color(unsigned char color){
    this->color_pair = color;
};

/*getters*/
char Character::get_sprite(){
    return this->sprite;
};

bool Character::get_state(){
    return this->state;
};

unsigned char Character::get_color(){
    return this->color_pair;
};

unsigned char Character::get_x(){
    return this->x;
};

unsigned char Character::get_y(){
    return this->y;
};
