#include "Map.hpp"

void Map::loadGameMap(const std::string &fileName){
    std::string readtext, filetext;

    std::ifstream mapfile(fileName);
    if (mapfile.is_open()){
        this->rows = 0;
        while (getline(mapfile, readtext)){
            this->map += readtext;
            this->rows++;
        }

        this->cols = this->map.size() / this->rows;
        mapfile.close();
    }
};