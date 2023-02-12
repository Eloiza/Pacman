#include "ChaseAggresive.hpp"

/*constructors*/
ChaseAggresive::ChaseAggresive(){
};

ChaseAggresive::ChaseAggresive(const Map *map, Cell *position, const Cell * pacmanPosition){
    this->map = map;
    this->setPacmanPosition(pacmanPosition);
    this->position = position;
    this->setTarget(pacmanPosition);
};

/*setters*/
void ChaseAggresive::setPacmanPosition(const Cell * pacmanPosition){
    this->pacmanPosition = pacmanPosition;
}

const Cell * ChaseAggresive::generateTarget(){
    return this->pacmanPosition;
};
