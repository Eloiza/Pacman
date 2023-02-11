#ifndef POKEY_BEHAVIOR_HPP
#define POKEY_BEHAVIOR_HPP

#include "Behavior.hpp"
#include <iostream>

class PokeyBehavior : public Behavior{
public:
    /*Constructors*/
    PokeyBehavior();
    PokeyBehavior(Map *map, Cell *position, const Cell *pacmanPosition, const Cell *cornerA, const Cell *cornerB);

    virtual ~PokeyBehavior() = default;

    virtual const Cell *generateTarget();

    /*setters*/
    void setPacmanPosition(const Cell *pacmanPosition); 
    void setCornerA(const Cell *cornerA);
    void setCornerB(const Cell *cornerB);


    private:
        const Cell *pacmanPosition;
        const Cell *cornerA;
        const Cell *cornerB;
    };

#endif