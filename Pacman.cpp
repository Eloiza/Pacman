#include "Pacman.hpp"

using namespace gameColors;

/*Constructors*/
Pacman::Pacman(){
};

Pacman::Pacman(unsigned int row, unsigned int col){
    this->setPosition(row, col);
    this->setPrevPosition(row, col);
    this->setColor((unsigned int) Colors::PACMAN);
    this->setSprite(MapElements::PACMAN);
    this->lives = 3;
    this->score = 0;
};

bool Pacman::isCollision(unsigned int row, unsigned int col){
    int testch;
    testch = mvinch(row, col);
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
unsigned int Pacman::getLives() const{
    return this->lives;
};

unsigned int Pacman::getScore() const{
    return this->score;
};

/*setters*/
void Pacman::setLives(const unsigned int lives){
    this->lives = lives;
};

void Pacman::setScore(const unsigned int score){
    this->score = score;
};
