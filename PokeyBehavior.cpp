#include "PokeyBehavior.hpp"

/*constructors*/
PokeyBehavior::PokeyBehavior(){};

PokeyBehavior::PokeyBehavior(Map *map, Cell *position, const Cell *pacmanPosition, const Cell *cornerA, const Cell *cornerB){
    this->map = map;
    this->position = position;
    this->setPacmanPosition(pacmanPosition);
    this->setCornerA(cornerA);
    this->setCornerB(cornerB);
};

/*setters*/
void PokeyBehavior::setPacmanPosition(const Cell *pacmanPosition){
    this->pacmanPosition = pacmanPosition;
}

void PokeyBehavior::setCornerA(const Cell * cornerA){
    this->cornerA = cornerA;
}

void PokeyBehavior::setCornerB(const Cell * cornerB){
    this->cornerB = cornerB;
}

const Cell *PokeyBehavior::generateTarget(){
    if(this->distance(this->position, this->pacmanPosition) > 8){
        return this->pacmanPosition;
    }
    unsigned int random_row;
    unsigned int random_col;

    // generate a new column index until get a valid one
    while (Character::isCollision(this->map, random_row, random_col) || random_row < 2){
        random_col = rand() % this->map->cols;
        random_row = rand() % this->map->rows;
    }
    
    return new Cell(random_row, random_col);
};
