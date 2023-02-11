#include "InkyBehavior.hpp"

/*Constructors*/
InkyBehavior::InkyBehavior(){
};

InkyBehavior::InkyBehavior(Map *map, Cell *position, const Cell *pacmanPosition, const Cell *blinkyPosition){
    this->map = map;
    this->position = position;
    this->setPacmanPosition(pacmanPosition);
    this->setBlinkyPosition(blinkyPosition);
};

const Cell * InkyBehavior::generateTarget(){
    int row, col;
    col = this->pacmanPosition->col + 2;

    if(col > this->map->cols - 1){
        row = this->pacmanPosition->row - 2;
    }

    float auxDistance = this->distance(this->blinkyPosition, this->pacmanPosition);

    if(this->pacmanPosition->row < this->position->row){
        row -= auxDistance;
        col -= auxDistance;
    }
    else{
        row += auxDistance;
        col += auxDistance;
    }
    // case invalid position try to adjust to a valid position
    if (Character::isCollision(this->map, row, col)){
        int auxRow=row, auxCol=col;
        int directions[7] = {0, -1, 1, -2, 2, -3, 3};

        //adjust the row
        for (int i = 0; i < 7; i++){
            for (int i = 0; i < 7; i++){
                // adjust the col
                if (!Character::isCollision(this->map, auxRow, auxCol) && col > 0 && col < this->map->cols - 1){
                    return new Cell(auxRow, auxCol);
                }
            }
        }

        //case still invalid
        return this->pacmanPosition;
    }

    return new Cell(row, col);
};

/*setters*/
void InkyBehavior::setPacmanPosition(const Cell * pacmanPosition){
    this->pacmanPosition = pacmanPosition;
};

void InkyBehavior::setBlinkyPosition(const Cell * blinkyPosition){
    this->blinkyPosition = blinkyPosition;
};