#ifndef RANDOM_BEHAVIOR_HPP
#define RANDOM_BEHAVIOR_HPP

#include "Behavior.hpp"
#include <cstdlib>

class RandomBehavior: public Behavior{
    public:
        /*constructors*/
        RandomBehavior();
        RandomBehavior(Map* map, Cell* ghostPosition);

        virtual ~RandomBehavior() = default;
        virtual Cell * generateTarget() override;
};

#endif