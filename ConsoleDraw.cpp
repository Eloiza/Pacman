#include "ConsoleDraw.hpp"
#include "Colors.hpp"
#include "MapElements.hpp"

#include <iostream>
using namespace gameColors;

void ConsoleDraw::initNcurses(int terminalWidth, int terminalHeight){
    initscr(); 
    cbreak();
    noecho();
    nodelay(stdscr, TRUE); 
    curs_set(FALSE); // hide cursor
    resizeterm(terminalWidth, terminalHeight);
};

void ConsoleDraw::initColors(){
    start_color();
    wattron(stdscr, A_BOLD);

    init_pair((short int) Colors::DEFAULT, COLOR_BLACK, COLOR_WHITE); // maze-color
    init_pair((short int) Colors::WALL, COLOR_BLUE, COLOR_BLUE);  // maze-color
    init_pair((short int) Colors::PACMAN, COLOR_YELLOW, COLOR_YELLOW); // pacman-color
};

void ConsoleDraw::drawGameScreen(){
    unsigned int i, j;
    for(i=0; i< (unsigned int) this->mapLin; i++){
        for(j=0; j< (unsigned int) this->mapCol; j++){
            mvaddch(i, j, this->gameMap[i* (unsigned int) this->mapCol+j]);
        }
    }
    refresh();
};

void ConsoleDraw::drawCharacter(Character &c) const{
    attron(COLOR_PAIR(Colors::DEFAULT));
    mvaddch(c.get_prev_y(), c.get_prev_x(), MapElements::EMPTY_SPACE);
    attroff(COLOR_PAIR(Colors::DEFAULT));

    attron(COLOR_PAIR(c.get_color()));
    mvaddch(c.get_y(), c.get_x(), c.get_sprite());
    attroff(COLOR_PAIR(c.get_color()));
};

void ConsoleDraw::drawCharacter(const unsigned char ch) const{
    erase();
    attron(COLOR_PAIR(1));
    mvaddch(0, 0, ch);
    attroff(COLOR_PAIR(1));
    move(0, 0);
};

void ConsoleDraw::drawCharacter(const unsigned char ch, const int y, const int x) const{
    erase();
    attron(COLOR_PAIR(1));
    mvaddch(y, x, ch);
    attroff(COLOR_PAIR(1));
    move(y, x);
};

void ConsoleDraw::drawCharacter(const unsigned char ch, const int y, const int x, const unsigned char color) const{
    erase();
    attron(COLOR_PAIR(color));
    mvaddch(y, x, ch);
    attroff(COLOR_PAIR(color));
    move(y, x);
};

void ConsoleDraw::endNcurses(){
    endwin();
};

void ConsoleDraw::loadGameMap(const std::string& fileName){
    std::string readtext, filetext; 
    
    std::ifstream mapfile(fileName);
    if(mapfile.is_open()){
        this->mapLin = 0;
        while (getline(mapfile, readtext)){
            this->gameMap += readtext;
            this->mapLin++;
        }

        this->mapCol = this->gameMap.size() / this->mapLin;
        mapfile.close();
    }
};

/*getters*/

void ConsoleDraw::getTerminalSize(const int *width, const int * height) const{
    width = &this->terminalWidth;
    height = &this->terminalHeight;
};

int ConsoleDraw::getTerminalWidth() const{
    return this->terminalWidth;
};

int ConsoleDraw::getTerminalHeight() const{
    return this->terminalHeight;
};

std::string ConsoleDraw::getGameMap() const{
    return this->gameMap;
}

int ConsoleDraw::getmapCol(){
    return (int) this->mapCol;
}

int ConsoleDraw::getmapLin(){
    return (int) this->mapLin;
}
/*setters*/

void ConsoleDraw::setTerminalSize(int width, int height){
    this->terminalWidth = width;
    this->terminalHeight = height;
};

void ConsoleDraw::setTerminalWidth(int width){
    this->terminalWidth = width;
};

void ConsoleDraw::setTerminalHeight(int height){
    this->terminalHeight = height;
};

void ConsoleDraw::setGameMap(std::string gameMap, unsigned char mapLin, unsigned char mapCol){
    this->gameMap = gameMap;
    this->mapLin = mapLin;
    this->mapCol = mapCol;
};
