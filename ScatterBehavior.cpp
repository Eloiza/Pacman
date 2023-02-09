#include "ScatterBehavior.hpp"

ScatterBehavior::ScatterBehavior(){
};

ScatterBehavior::ScatterBehavior(Map *map, Cell *position, Cell * cornerA, Cell * cornerB){
    this->map = map;
    this->position = position;
    this->cornerA = cornerA;
    this->cornerB = cornerB;
};

const Cell * ScatterBehavior::generateTarget(){
    if (this->distance(this->position, this->cornerA) < this->distance(this->position, this->cornerB)){
        return this->cornerB;
    }

    return this->cornerA;
};
