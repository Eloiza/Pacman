#ifndef FRIGHTENED_BEHAVIOR_HPP
#define FRIGHTENED_BEHAVIOR_HPP

#include "Behavior.hpp"
#include <cstdlib>

class FrightenedBehavior: public Behavior{
    public:
        /*constructors*/
        FrightenedBehavior();
        FrightenedBehavior(Map* map, Cell* ghostPosition);

        virtual ~FrightenedBehavior() = default;
        virtual Cell * generateTarget() override;
};

#endif