#include "Map.hpp"

void Map::loadGameMap(const std::string &fileName){
    std::string readtext, filetext;

    std::ifstream mapfile(fileName);
    if (mapfile.is_open()){
        this->lin = 0;
        while (getline(mapfile, readtext)){
            this->map += readtext;
            this->lin++;
        }

        this->col = this->map.size() / this->lin;
        mapfile.close();
    }
};