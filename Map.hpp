#include <string>
#include <fstream>

class Map{
    public:
        void loadGameMap(const std::string& fileName);
        std::string map;
        unsigned int col;
        unsigned int lin;
};