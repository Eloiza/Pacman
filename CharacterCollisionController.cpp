#include "CharacterCollisionController.hpp"
#include <iostream>
CharacterCollisionController::CharacterCollisionController(){
};

CharacterCollisionController::CharacterCollisionController(Pacman * pacman, std::list<Ghost *> ghosts) : pacman{pacman}, ghosts{ghosts}{
};

bool CharacterCollisionController::checkCollisions(){
    std::list<Ghost *>::iterator ghost_it = this->ghosts.begin();
    for(; ghost_it != this->ghosts.end(); ghost_it ++){
        if ((*ghost_it)->getPosition()->row == this->pacman->getPosition()->row &&
            (*ghost_it)->getPosition()->col == this->pacman->getPosition()->col){
            if(this->pacman->isInvencible()){
                (*ghost_it)->activateRetreatBehavior();
                return 0;
            }
            else{
                this->pacman->decreaseLive();
                this->pacman->restart();
                this->restartGhosts();
                return 1;
            }
        }
    }
    return 0;
};

void CharacterCollisionController::restartGhosts(){
    std::list<Ghost *>::iterator ghost_it = this->ghosts.begin();
    for (; ghost_it != this->ghosts.end(); ghost_it++){
        (*ghost_it)->restart();
    }
}
