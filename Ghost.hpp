#ifndef GHOST_HPP
#define GHOST_HPP 

#include <list>
#include <iostream>
#include "Clock.hpp"
#include "Colors.hpp"
#include "GhostBehaviorId.hpp"
#include "Character.hpp"

#include "Chase.hpp"
#include "Scatter.hpp"
#include "Behavior.hpp"
#include "FrightenedBehavior.hpp"

class Ghost : public Character{
    public:
        /*constructors*/
        Ghost(unsigned int row, unsigned int col);
        Ghost(const Map * map, unsigned int row, unsigned int col, Chase * chaseBh, Scatter * scatterBh, FrightenedBehavior * frightenedBh);

        virtual ~Ghost() = default;

        void move(bool pacmanInvencible);

        /*setters*/
        void setTarget(Cell * const target);
        void setActiveBehavior(Behavior * behavior);

        void setChaseBehavior(Chase * chase);
        void setScatterBehavior(Scatter * scatter);
        void setFrightenedBehavior(FrightenedBehavior * frightened);

        void activateChaseBehavior();
        void activateScatterBehavior();
        void activateRetreatBehavior();
        void deactivateRetreatBehavior();

        void activateFrightenedBehavior();
        void deactivateFrightenedBehavior();

        void updateBehavior(bool pacmanInvencible);
        void startClock();
        Behavior *activeBehavior;
        short int curBehaviorId;

    protected:
        const Map * map;
        short int defaultColor;
        Cell * startPosition;
        Chase *chase;
        Scatter *scatter;
        FrightenedBehavior *frightened;
        /*Behavior internal control*/

        Clock behaviorClock;
        using ms = std::chrono::duration<double, std::milli>;
        ms chaseDuration;
        ms scatterDuration;
        ms deadDuration;
        ms frightenedDuration;
};

#endif