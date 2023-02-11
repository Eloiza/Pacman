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

        void move();

        /*setters*/
        void setTarget(Cell * const target);
        void setActiveBehavior(Behavior * behavior);

        void setChaseBehavior(Chase * chase);
        void setScatterBehavior(Scatter * scatter);
        void setFrightenedBehavior(FrightenedBehavior * frightened);

        void activateChaseBehavior();
        void activateScatterBehavior();
        void activateFrightenedBehavior();

        void updateBehavior();
        void startClock();

    protected:
        const Map * map;
        Chase *chase;
        Scatter *scatter;
        Behavior * activeBehavior;
        FrightenedBehavior *frightened;

        /*Behavior internal control*/
        short int curBehaviorId;

        Clock behaviorClock;
        using ms = std::chrono::duration<double, std::milli>;
        ms chaseDuration;
        ms scatterDuration;
        ms deadDuration;
        ms frightenedDuration;
};

#endif