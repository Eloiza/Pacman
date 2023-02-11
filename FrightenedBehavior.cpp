#include "FrightenedBehavior.hpp"

FrightenedBehavior::FrightenedBehavior(){
};

FrightenedBehavior::FrightenedBehavior(Map *map, Cell *ghostPosition){
    this->setMap(map);
    this->setPosition(ghostPosition);
};

Cell * FrightenedBehavior::generateTarget(){
    /*generate a number between -3 and 3*/
    unsigned int random_row;
    unsigned int random_col;
    
    // generate a new column index until get a valid one
    while(Character::isCollision(this->map, random_row, random_col) || random_row < 2){
        random_col = rand() % this->map->cols;
        random_row = rand() % this->map->rows;
    }

    return new Cell(random_row, random_col);
};
