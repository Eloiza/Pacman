#ifndef GHOST_HPP
#define GHOST_HPP 

#include "Character.hpp"
#include <list>
#include <cmath>
#include <string> 
#include <map> 

class Ghost : public Character{
    public:
        /*constructors*/
        Ghost();
        Ghost(char sprite, unsigned char color_pair, unsigned char y, unsigned char x);

        double distance(std::pair<unsigned char, unsigned char> p1, std::pair<unsigned char, unsigned char> p2);
        void generateTarget(std::pair<unsigned char, unsigned char> pacman_position);
        // pathFind();
        std::list<std::pair<unsigned char, unsigned char>> getNeighbors(std::string map, std::pair<unsigned char, unsigned char> position);

    protected:
        std::pair<unsigned char, unsigned char> target;
};

#endif