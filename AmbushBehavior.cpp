#include "AmbushBehavior.hpp"

/*constructors*/
AmbushBehavior::AmbushBehavior(){
};

AmbushBehavior::AmbushBehavior(Map *map, Cell *position, const Cell * pacmanPosition, unsigned int pointsAhead){
    this->map = map;
    this->position= position;
    this->setPacmanPosition(pacmanPosition);
    this->setTarget(pacmanPosition);
    this->pointsAhead = pointsAhead;
};

/*setters*/
void AmbushBehavior::setPacmanPosition(const Cell * pacmanPosition){
    this->pacmanPosition = pacmanPosition;
}

const Cell * AmbushBehavior::generateTarget(){
    //try to set target as pacmanPosition +4/-4 columns or +4/-4 rows
    int dist;
    unsigned int pointsAheadcopy = this->pointsAhead;
    for (dist = pointsAheadcopy; dist > 0; dist--){
        int dx[4] = {+dist, -dist, 0, 0};
        int dy[4] = {0, 0, +dist, -dist};
        unsigned int new_row, new_col;

        for (unsigned int i = 0; i < 4; i++){
            //case valid position
            if (!Character::isCollision(this->map, this->pacmanPosition->row + dy[i], this->pacmanPosition->col + dx[i])){
                new_row = this->pacmanPosition->row + dy[i];
                new_col = this->pacmanPosition->col + dx[i];

                return new Cell(new_row, new_col);
            };
        };
    }

    return this->pacmanPosition;
};
