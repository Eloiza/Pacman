#include "Scatter.hpp"

Scatter::~Scatter(){
    delete this->cornerA;
    delete this->cornerB;
};

Scatter::Scatter(Map *map, Cell *position, Cell *cornerA, Cell *cornerB){
    this->setMap(map);
    this->setPosition(position);
    this->cornerA = cornerA;
    this->cornerB = cornerB;
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
