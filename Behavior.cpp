#include "Behavior.hpp"

void Behavior::setMap(Map *map){
    this->map = map;
};

void Behavior::setTarget(Cell *target){
    bool within_map_range = target->col < map->cols && target->row < map->rows;
    bool not_collison = !Character::isCollision(this->map, target);

    if (within_map_range && not_collison){
        if (target != this->position){
            this->target = target;
            this->setTargetPath(this->generateTargetPath());
        }
        else{
            // set target with empty list
            this->target = target;
            this->setTargetPath(std::list<Cell *>());
        }
    }
    else{
        throw InvalidPositionException(target);
    }
};

void Behavior::setPosition(Cell *position){
    this->position = position;
};

void Behavior::setTargetPath(std::list<Cell *> targetPath){
    this->targetPath = targetPath;
};

/*getters*/
Cell * Behavior::getTarget(){
    return this->target;
};

Cell * Behavior::getNextPosition(){
    if (!this->targetPath.empty()){
        Cell * ret = this->targetPath.front();
        this->targetPath.pop_front();
        return ret;
    }

    return this->position;
};
