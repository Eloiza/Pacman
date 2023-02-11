#ifndef CHASE_AGGRESIVE_HPP
#define CHASE_AGGRESIVE_HPP

#include "Chase.hpp"

class ChaseAggresive : public Chase{
    public:
        /*Constructors*/
        ChaseAggresive();
        ChaseAggresive(Map* map, Cell * position, const Cell * pacmanPosition);

        virtual ~ChaseAggresive() = default;

        virtual const Cell * generateTarget();

        /*setters*/
        void setPacmanPosition(const Cell * pacmanPosition);


    private:
        const Cell * pacmanPosition;
};

#endif