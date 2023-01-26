#include "Pacman.hpp"

using namespace gameColors;

/*Constructors*/
Pacman::Pacman(){
};

Pacman::Pacman(char sprite, unsigned char y, unsigned char x)
:Character(sprite, y, x){
    this->color_pair = (unsigned char) Colors::PACMAN;
    this->lives = 3;
    this->score = 0;
};

bool Pacman::collision(unsigned char y, unsigned char x){
    int testch;
    testch = mvinch(y, x);
    switch (testch & A_CHARTEXT){
        case MapElements::POINT:
            this->score++;
            return 0; 
        case MapElements::GHOST:
            this->lives--;
            return 1;
        case MapElements::WALL:
            return 1;
    }
    return 0;
};

/*getters*/
unsigned int Pacman::get_lives() const{
    return this->lives;
};

unsigned int Pacman::get_score() const{
    return this->score;
};

/*setters*/
void Pacman::set_lives(const unsigned int lives){
    this->lives = lives;
};

void Pacman::set_score(const unsigned int score){
    this->score = score;
};
