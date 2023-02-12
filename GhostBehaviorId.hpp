#ifndef BEHAVIORS_ID_HPP
#define BEHAVIORS_ID_HPP

namespace behaviorsId{
    enum class GhostBehaviorId : short int{
        DEAD,
        FRIGHTENED,
        CHASE, 
        SCATTER, 
        RETREAT, 
        IN_JAIL,
    };
}

#endif