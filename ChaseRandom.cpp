#include "ChaseRandom.hpp"

/*constructors*/
ChaseRandom::ChaseRandom(){};

ChaseRandom::ChaseRandom(Map *map, Cell *position, const Cell *pacmanPosition){
    this->map = map;
    this->position = position;
    this->setPacmanPosition(pacmanPosition);
};

/*setters*/
void ChaseRandom::setPacmanPosition(const Cell *pacmanPosition){
    this->pacmanPosition = pacmanPosition;
}

const Cell *ChaseRandom::generateTarget(){
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
