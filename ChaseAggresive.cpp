#include "ChaseAggresive.hpp"

/*constructors*/
ChaseAggresive::ChaseAggresive(){
};

ChaseAggresive::ChaseAggresive(Map *map, Cell *position, const Cell * pacmanPosition){
    this->map = map;
    this->position= position;
    this->setPacmanPosition(pacmanPosition);
    this->setTarget(pacmanPosition);
};

/*setters*/
void ChaseAggresive::setPacmanPosition(const Cell * pacmanPosition){
    this->pacmanPosition = pacmanPosition;
}

const Cell * ChaseAggresive::generateTarget(){
    return this->pacmanPosition;
};
