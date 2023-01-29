#include "ConsoleDraw.hpp"
#include "Colors.hpp"
#include "MapElements.hpp"
#include "Map.hpp"

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

void ConsoleDraw::drawGameScreen(Map * gameMap){
    unsigned int i, j;
    for(i=0; i< (unsigned int) gameMap->lin; i++){
        for(j=0; j< (unsigned int) gameMap->col; j++){
            mvaddch(i, j, gameMap->map[i* (unsigned int) gameMap->col+j]);
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

void ConsoleDraw::drawScore(unsigned int score){
    mvaddch(0, 8, (char) score);
    refresh();
};

void ConsoleDraw::endNcurses(){
    endwin();
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
