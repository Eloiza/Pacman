#ifndef CHASE_BEHAVIOR_HPP
#define CHASE_BEHAVIOR_HPP

#include "Behavior.hpp"
#include "Character.hpp"
#include "Cell.hpp"
#include "Node.hpp"
#include "Map.hpp"
#include <list>
#include <cmath>
#include <algorithm>
#include <iostream>

class ChaseBehavior : public Behavior{
    public:
        /*Constructors*/
        ChaseBehavior();
        ChaseBehavior(Map* map, Cell * position, Cell *target);

        virtual ~ChaseBehavior() = default;

        virtual std::list<Cell *> generateTargetPath() override;

    private:
        /*A-start pathfinding functions*/
        double distance(const Cell *p1, const Cell *p2);
        double distance(unsigned int x, unsigned int y, const Cell *p2);
        std::list<Cell *> reconstructPath(Node *startNode, Node *lastNode);
        std::list<Node *> getNeighbors(const Cell *n);
};

#endif