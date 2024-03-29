#ifndef BEHAVIOR_HPP
#define BEHAVIOR_HPP

#include "Map.hpp"
#include "Node.hpp"
#include "Cell.hpp"
#include "Character.hpp"
#include "InvalidPositionException.hpp"

#include <list>
#include <cmath>
#include <algorithm>

class Behavior{
    /*abstract class to implement a behavior basic structures*/
    public:
        virtual ~Behavior() = default;

        /*setters*/
        virtual void setTarget(const Cell * target);
        virtual void setPosition(Cell * position);
        virtual void setTargetPath(std::list<Cell *> targetPath);
        virtual void setMap(const Map * map);

        /*getters*/
        virtual const Cell * getTarget();
        virtual Cell * getNextPosition();

        /*generators*/
        virtual std::list<Cell *> generateTargetPath();
        virtual const Cell * generateTarget() = 0;

        /*aux functions to generateTargetPath*/
        double distance(const Cell *p1, const Cell *p2);
        double distance(unsigned int x, unsigned int y, const Cell *p2);
        std::list<Cell *> reconstructPath(Node *startNode, Node *lastNode);
        std::list<Node *> getNeighbors(const Cell *n);

    protected:
        const Cell * target;
        Cell * position;
        std::list<Cell *> targetPath;
        const Map * map;
};

#endif