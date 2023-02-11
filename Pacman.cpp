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
    testch = testch & A_CHARTEXT;

    if(MapElements::POINT){
        this->score += 10;
        return 0;
    }
    else if (MapElements::WALL){
        return 1;
    }
    else if (MapElements::VITAMIN){
        this->score += 50;
        this->activateInvencible();
        return 0;
    }
    else if(MapElements::GHOST && this->isInvencible()){
        this->score +=200;
        return 0;
    }
    else if(MapElements::GHOST && !this->isInvencible()){
        this->lives--;
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

void Pacman::activateInvencible(){
    this->invencible = 1;
    this->stateClock.start();
};

void Pacman::deactivateInvencible(){
    this->invencible = 0;
};

bool Pacman::isInvencible(){
    return this->invencible;
}

bool Pacman::isDead(){
    return this->lives > 0;
};

void Pacman::updateState(){
    ms duration = this->stateClock.end();
    if(this->isInvencible() && duration > this->invencibleDuration){
        this->deactivateInvencible();
        this->stateClock.start();
    }
}