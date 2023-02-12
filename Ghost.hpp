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
        Ghost(const Map *map, unsigned int row, unsigned int col, unsigned int color);
        Ghost(const Map *map, unsigned int row, unsigned int col, Chase *chaseBh, Scatter *scatterBh, FrightenedBehavior *frightenedBh);
        Ghost(const Map *map, unsigned int row, unsigned int col, Chase *chaseBh, Scatter *scatterBh, FrightenedBehavior *frightenedBh, bool startJail, double jailTimeMS);

        virtual ~Ghost() = default;

        void move(bool pacmanInvencible);
        void restart() override;

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

        void activateInJailBehavior();
        void deactivateInJailBehavior();

        void activateFrightenedBehavior();
        void deactivateFrightenedBehavior();

        void updateBehavior(bool pacmanInvencible);
        void startClock();

    protected:
        const Map * map;
        short int defaultColor;
        short int curBehaviorId;

        Cell * startPosition;
        const Cell * cornerA;
        const Cell * cornerB;

        Chase *chase;
        Scatter *scatter;
        Behavior *activeBehavior;
        FrightenedBehavior *frightened;
        bool enableFrightened;
        bool startInJail;

        /*Behavior internal control*/
        Clock behaviorClock;
        using ms = std::chrono::duration<double, std::milli>;
        ms chaseDuration;
        ms scatterDuration;
        ms deadDuration;
        ms frightenedDuration;
        ms jailDuration;
};

#endif