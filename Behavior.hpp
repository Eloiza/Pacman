#ifndef BEHAVIOR_HPP
#define BEHAVIOR_HPP

#include "Map.hpp"
#include "Cell.hpp"
#include "Character.hpp"
#include "InvalidPositionException.cpp"
#include <list>

class Behavior{
    /*abstract class to implement a behavior basic structures*/
    public:
        virtual ~Behavior() = default;

        /*setters*/
        virtual void setTarget(Cell *target);
        virtual void setPosition(Cell *position);
        virtual void setTargetPath(std::list<Cell *> targetPath);
        virtual void setMap(Map * map);
        
        /*getters*/
        virtual Cell * getTarget();
        virtual Cell * getNextPosition();
        virtual std::list<Cell *> getTargetPath() const = 0;

    protected:
        Cell * target;
        Cell * position;
        std::list<Cell *> targetPath;
        Map * map;
};

#endif