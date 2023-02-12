#include "Scatter.hpp"

Scatter::Scatter(const Map *map, Cell *position, const Cell *cornerA, const Cell *cornerB){
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

const Cell * Scatter::getCornerA(){
    return this->cornerA;
};
const Cell * Scatter::getCornerB(){
    return this->cornerB;
};
