#ifndef CHASE_SIEGE_HPP
#define CHASE_SIEGE_HPP

#include "Chase.hpp"
#include <algorithm>

class ChaseSiege : public Chase{
    public:
        /*Constructors*/
        ChaseSiege();
        ChaseSiege(Map *map, Cell *position, const Cell * pacmanPosition, const Cell * pairGhostPosition);

        virtual ~ChaseSiege() = default;

        virtual const Cell *generateTarget();

        /*setters*/
        void setPacmanPosition(const Cell *pacmanPosition);
        void setPairGhostPosition(const Cell *pairGhostPosition);

    private:
        const Cell * pacmanPosition; 
        const Cell * pairGhostPosition;

};
#endif