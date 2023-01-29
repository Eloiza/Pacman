#ifndef MAP_HPP
#define MAP_HPP

#include <string>
#include <fstream>

class Map{
    public:
        void loadGameMap(const std::string& fileName);
        std::string map;
        unsigned int cols;
        unsigned int rows;
};
#endif