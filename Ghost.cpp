#include "Ghost.hpp"

/*constructors*/
Ghost::Ghost(){
};
Ghost::Ghost(char sprite, unsigned char color_pair, unsigned char y, unsigned char x)
: Character(sprite, color_pair, y, x){
};

double Ghost::distance(std::pair<unsigned char, unsigned char> p1, std::pair<unsigned char, unsigned char> p2){
    /*implements manhathan distance*/
    return abs(p2.first - p1.first) + abs(p2.second - p1.second);
};

void Ghost::generateTarget(std::pair<unsigned char, unsigned char> pacman_position){
    this->target = pacman_position;
};

std::list<std::pair<unsigned char, unsigned char>> pathFind(std::string map){
    /*Implements A* algorithm*/

    // The set of discovered nodes that may need to be (re-)expanded.
    // Initially, only the start node is known.
    // This is usually implemented as a min-heap or priority queue rather than a hash-set.
    std::pair<unsigned char, unsigned char> start(this->x, this->y);
    std::pair<unsigned char, unsigned char> current((unsigned char)0, (unsigned char)0);

    std::list<std::pair<unsigned char, unsigned char>> openSet;
    openSet.push_back(std::make_pair(this->x, this->y));

    // For node n, cameFrom[n] is the node immediately preceding it on the cheapest path from start
    // to n currently known.
    std::list<std::pair<unsigned char, unsigned char>> cameFrom;

    // For node n, gScore[n] is the cost of the cheapest path from start to n currently known.
    std::list<unsigned int> gScore;
    gScore.push_back(0);

    // For node n, fScore[n] := gScore[n] + h(n). fScore[n] represents our current best guess as to
    // how cheap a path could be from start to finish if it goes through n.
    std::list<unsigned int> fScore;
    gScore.push_back(0);

    while(!openSet.empty()){

    }
    while openSet is not empty
        // This operation can occur in O(Log(N)) time if openSet is a min-heap or a priority queue
        current := the node in openSet having the lowest fScore[] value
        if current = goal
            return reconstruct_path(cameFrom, current)

        openSet.Remove(current)
        for each neighbor of current
            // d(current,neighbor) is the weight of the edge from current to neighbor
            // tentative_gScore is the distance from start to the neighbor through current
            tentative_gScore := gScore[current] + d(current, neighbor)
            if tentative_gScore < gScore[neighbor]
                // This path to neighbor is better than any previous one. Record it!
                cameFrom[neighbor] := current
                gScore[neighbor] := tentative_gScore
                fScore[neighbor] := tentative_gScore + h(neighbor)
                if neighbor not in openSet
                    openSet.add(neighbor)

    // Open set is empty but goal was never reached
    return failure
};

std::list<std::pair<unsigned char, unsigned char>> Ghost::getNeighbors(std::string map, std::pair<unsigned char, unsigned char> position){
    unsigned int x, y;
    x = position.first;
    y = position.second;

    std::list<std::pair<unsigned char, unsigned char>> valid_neighbors;
    if(!collision(y, x + 1)){
        valid_neighbors.push_back(std::make_pair(x+1, y));
    }
    if (!collision(y, x - 1)){
        valid_neighbors.push_back(std::make_pair(x + 1, y));
    }

    if (!collision(y + 1, x)){
        valid_neighbors.push_back(std::make_pair(x + 1, y));
    }
    if (!collision(y - 1 , x)){
        valid_neighbors.push_back(std::make_pair(x + 1, y));
    }

    return valid_neighbors;
};
