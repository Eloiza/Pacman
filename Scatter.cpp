#include "Scatter.hpp"

Scatter::Scatter(Map *map, Cell *position, Cell *cornerA, Cell *cornerB){
    this->setMap(map);
    this->cornerA = cornerA;
    this->cornerB = cornerB;
    this->setPosition(position);
};

void Scatter::setCornersPosition(const Cell *cornerA, const Cell *cornerB){
    this->cornerA = cornerA;
    this->cornerB = cornerB;
};

const Cell * Scatter::generateTarget(){
    if (this->distance(this->position, this->cornerA) < this->distance(this->position, this->cornerB)){
        return this->cornerB;
    }
    return this->cornerA;
};

// void Scatter::setPosition(Cell *position){
//     this->position = position;
//     this->setTarget(this->generateTarget());
// };