#include "Chase.hpp"

class ChaseAmbush : public Chase{
    public:
        ChaseAmbush();
        ChaseAmbush(Map *map, Cell *position, const Cell *pacmanPosition, unsigned int pointsAhed);

        virtual ~ChaseAmbush() = default;

        virtual const Cell * generateTarget();

        /*setters*/
        void setPacmanPosition(const Cell *pacmanPosition);

    private:
        const Cell * pacmanPosition;
        unsigned int pointsAhead;
};