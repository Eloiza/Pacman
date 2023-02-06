#include "ChaseBehavior.hpp"

/*constructors*/
ChaseBehavior::ChaseBehavior(){
};

ChaseBehavior::ChaseBehavior(Map *map, Cell *position, Cell * pacmanPosition){
    this->map = map;
    this->position= position;
    this->setPacmanPosition(pacmanPosition);
    this->setTarget(pacmanPosition);
};

/*setters*/
void ChaseBehavior::setPacmanPosition(Cell * pacmanPosition){
    this->pacmanPosition = pacmanPosition;
}

Cell * ChaseBehavior::generateTarget(){
    return this->pacmanPosition;
};
