#ifndef CHASE_RANDOM_HPP
#define CHASE_RANDOM_HPP

#include "Chase.hpp"

class ChaseRandom : public Chase{
public:
    /*Constructors*/
    ChaseRandom();
    ChaseRandom(Map *map, Cell *position, const Cell *pacmanPosition);

    virtual ~ChaseRandom() = default;

    virtual const Cell *generateTarget();

    /*setters*/
    void setPacmanPosition(const Cell *pacmanPosition); 


    private:
        const Cell *pacmanPosition;
    };

#endif