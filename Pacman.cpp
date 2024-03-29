#include "Pacman.hpp"

using namespace gameColors;

/*Constructors*/
Pacman::Pacman(){
};

Pacman::Pacman(unsigned int row, unsigned int col){
    this->startPosition = new Cell(row, col);
    this->setPosition(row, col);
    this->setPrevPosition(row, col);
    this->setColor((unsigned int) Colors::PACMAN);
    this->setSprite(MapElements::PACMAN);
    this->lives = 3;
    this->score = 0;
    this->invencibleDuration = (ms) 8000;
};

bool Pacman::isCollision(unsigned int row, unsigned int col){
    int testch;
    testch = mvinch(row, col);
    testch = testch & A_CHARTEXT;
    this->lostLive = 0;

    if(testch == MapElements::POINT){
        this->score += 10;
        return 0;
    }
    else if (testch == MapElements::WALL){
        return 1;
    }
    else if (testch == MapElements::VITAMIN){
        this->score += 50;
        this->activateInvencible();
        return 0;
    }
    else if(testch == MapElements::GHOST && this->isInvencible()){
        this->score +=200;
        return 0;
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

void Pacman::decreaseLive(){
    this->lives = lives - 1;
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
    return this->lives <= 0;
};

void Pacman::updateState(){
    if(this->isInvencible()){
        ms duration = this->stateClock.end();
        if(duration > this->invencibleDuration){
            this->deactivateInvencible();
            this->stateClock.start();
        }
    } 

}
