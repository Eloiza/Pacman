#include "CharacterCollisionController.hpp"
#include <iostream>
CharacterCollisionController::CharacterCollisionController(){
};

CharacterCollisionController::CharacterCollisionController(Pacman * pacman, std::list<Ghost *> ghosts) : pacman{pacman}, ghosts{ghosts}{
};

void CharacterCollisionController::checkCollisions(){
    std::list<Ghost *>::iterator ghost_it = this->ghosts.begin();
    for(; ghost_it != this->ghosts.end(); ghost_it ++){
        if ((*ghost_it)->getPosition()->row == this->pacman->getPosition()->row &&
            (*ghost_it)->getPosition()->col == this->pacman->getPosition()->col){
            if(this->pacman->isInvencible()){
                (*ghost_it)->activateRetreatBehavior();
                std::cout << "GHOST RETREAT" << std::endl;
            }
            else{
                this->pacman->decreaseLive();
                this->pacman->restart();
                this->restartGhosts();
                return;
            }
        }
    }
};

void CharacterCollisionController::restartGhosts(){
    std::list<Ghost *>::iterator ghost_it = this->ghosts.begin();
    for (; ghost_it != this->ghosts.end(); ghost_it++){
        (*ghost_it)->restart();
    }
}
