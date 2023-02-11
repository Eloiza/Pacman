#include "Behavior.hpp"
#include <iostream> 

void Behavior::setMap(Map *map){
    this->map = map;
};

void Behavior::setTarget(const Cell * target){
    bool within_map_range = target->col < map->cols && target->row < map->rows;
    bool not_collison = !Character::isCollision(this->map, target);

    if (within_map_range && not_collison){
        if (target != this->position){
            this->target = target;
            this->setTargetPath(this->generateTargetPath());
        }
        else{
            // set target with empty list
            this->target = target;
            this->setTargetPath(std::list<Cell *>());
        }
    }
    else{
        throw InvalidPositionException(target);
    }
};

void Behavior::setPosition(Cell * position){
    this->position = position;
    // this->setTarget(this->generateTarget());
};

void Behavior::setTargetPath(std::list<Cell *> targetPath){
    this->targetPath = targetPath;
};

/*getters*/
const Cell * Behavior::getTarget(){
    return this->target;
};

Cell * Behavior::getNextPosition(){
    //case reached goal generate more steps
    if (this->targetPath.empty()){
        this->setTarget(this->generateTarget());
    }
    
    else{
        Cell * ret = this->targetPath.front();
        this->targetPath.pop_front();
        this->setPosition(ret);
        return ret;
    }

    return this->position;
};

double Behavior::distance(const Cell *p1, const Cell *p2){
    return abs(p2->row - p1->row) + abs(p2->col - p1->col);
};

double Behavior::distance(unsigned int row, unsigned int col, const Cell *p2){
    return abs(p2->row - row) + abs(p2->col - col);
};

std::list<Cell *> Behavior::reconstructPath(Node *startNode, Node *lastNode){
    std::list<Cell *> path;
    Node *current = lastNode;
    while (current->parent != nullptr)
    {
        path.push_front(current);
        current = current->parent;
    }

    return path;
};

std::list<Cell *> Behavior::generateTargetPath(){
    std::list<Node *> openSet;
    std::list<Node *> closeSet;
    std::list<Node *> neighbors;

    Node *start = new Node(this->position, 0, this->distance(this->position, this->target));
    start->parent = nullptr;
    openSet.push_back(start);

    Node *current;
    double tentative_gScore;
    std::list<Node *>::iterator nodeIt;
    while (!openSet.empty())
    {
        openSet.sort([](const Node *n1, const Node *n2)
                     { return n1->f < n2->f; });

        current = openSet.front();
        if (current->row == this->target->row && current->col == this->target->col)
        {
            return this->reconstructPath(start, current);
        }
        openSet.pop_front(); // remove first node
        closeSet.push_back(current);
        neighbors = this->getNeighbors(current);

        for (nodeIt = neighbors.begin(); nodeIt != neighbors.end(); nodeIt++){
            tentative_gScore = current->g + 1;
            auto foundNodeOpenSet = std::find_if(openSet.begin(), openSet.end(), [&](Node const *cNode)
                                                 { return cNode->row == (*nodeIt)->row && cNode->col == (*nodeIt)->col; });

            auto foundNodeCloseSet = std::find_if(closeSet.begin(), closeSet.end(), [&](Node const *cNode)
                                                  { return cNode->row == (*nodeIt)->row && cNode->col == (*nodeIt)->col; });

            // if node not in openSet or closeSet
            if (foundNodeOpenSet == openSet.end() && foundNodeCloseSet == closeSet.end())
            {
                (*nodeIt)->g = tentative_gScore;
                (*nodeIt)->f = tentative_gScore + this->distance(*nodeIt, this->target);
                (*nodeIt)->parent = current;
                openSet.push_back(*nodeIt);
            }

            else if (tentative_gScore < (*nodeIt)->g)
            {
                (*nodeIt)->g = tentative_gScore;
                (*nodeIt)->f = tentative_gScore + this->distance(*nodeIt, this->target);
                (*nodeIt)->parent = current;
            }
        }
    }
    return std::list<Cell *>();
};

std::list<Node *> Behavior::getNeighbors(const Cell *n){
    std::list<Node *> valid_neighbors;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    for (int i = 0; i < 4; i++)
    {
        int col = n->col + dx[i];
        int row = n->row + dy[i];

        // Check if the neighbor is within the boundaries of the map
        if (col >= 0 && col < (int)map->cols && row >= 0 && row < (int)map->rows && !Character::isCollision(map, row, col))
        {
            valid_neighbors.push_back(new Node(row, col, distance(row, col, this->target)));
        }
    }

    return valid_neighbors;
}
