#include "Behavior.hpp"

class AmbushBehavior : public Behavior{
    public:
        AmbushBehavior();
        AmbushBehavior(Map *map, Cell *position, Cell *pacmanPosition, unsigned int pointsAhed);

        virtual ~AmbushBehavior() = default;

        virtual const Cell * generateTarget();

        /*setters*/
        void setPacmanPosition(Cell *pacmanPosition);

    private:
        const Cell * pacmanPosition;
        unsigned int pointsAhead;
};