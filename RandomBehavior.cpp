#include "RandomBehavior.hpp"

RandomBehavior::RandomBehavior(){
};

RandomBehavior::RandomBehavior(Map *map, Cell *ghostPosition){
    this->setMap(map);
    this->setPosition(ghostPosition);
};

Cell * RandomBehavior::generateTarget(){
    /*generate a number between -3 and 3*/
    unsigned int random_row = ((rand() % 3) - 3) + this->position->row;
    unsigned int random_col = ((rand() % this->map->cols));
    
    // generate a new column index until get a valid one
    while(Character::isCollision(this->map, random_row, random_col)){
        random_col = (rand() % this->map->cols);
    }
    return new Cell(random_row, random_col);
};
