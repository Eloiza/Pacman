#ifndef CHARACTER_COLLISION_CONTROLLER
#define CHARACTER_COLLISION_CONTROLLER

#include "Ghost.hpp"
#include "Pacman.hpp"

class CharacterCollisionController{
    public:
        CharacterCollisionController();
        CharacterCollisionController(Pacman *pacman, std::list<Ghost *> ghosts);
        bool checkCollisions();
        void restartGhosts();
    private:
        Pacman * pacman;
        std::list<Ghost *> ghosts;
};
#endif