#ifndef CHASE_BEHAVIOR_HPP
#define CHASE_BEHAVIOR_HPP

#include "Character.hpp"
#include "Cell.hpp"
#include "Node.hpp"
#include "Map.hpp"
#include <list>
#include <cmath>
#include <algorithm>
#include <iostream>

class ChaseBehavior{
    public:
        /*Constructors*/
        ChaseBehavior();
        ChaseBehavior(Map* map, Cell * position, Cell *target);

        virtual ~ChaseBehavior() = default;
        
        double distance(const Cell *p1, const Cell *p2);
        double distance(unsigned int x, unsigned int y, const Cell *p2);

        /*A-start pathfinding functions*/
        void generateTarget(Cell *targetPosition);
        Cell* generateDirection();
        std::list<Cell *> reconstructPath(Node *startNode, Node *lastNode);
        std::list<Cell *> generatePath();
        std::list<Node *> getNeighbors(const Cell *n);

        /*setters*/
        void setTarget(Cell *const target);
        void setDirections(std::list<Cell *> directions);

        /*getters*/

    private:
        Cell * target;
        Cell * position;
        std::list<Cell *> directions;
        const Map *map;
};

#endif