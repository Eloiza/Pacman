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

    init_pair((short int) Colors::DEFAULT, COLOR_BLACK, COLOR_WHITE);
    init_pair((short int) Colors::WALL, COLOR_BLUE, COLOR_BLUE); 
    init_pair((short int) Colors::PACMAN, COLOR_YELLOW, COLOR_YELLOW); 
    init_pair((short int) Colors::GENERIC_GHOST, COLOR_WHITE, COLOR_WHITE);
    init_pair((short int) Colors::FRIGHTENED_GHOST, COLOR_WHITE, COLOR_BLUE);
};

void ConsoleDraw::drawGameScreen(Map * gameMap){
    unsigned int i, j;
    for(i=0; i< (unsigned int) gameMap->rows; i++){
        for(j=0; j< (unsigned int) gameMap->cols; j++){
            mvaddch(i, j, gameMap->map[i* (unsigned int) gameMap->cols+j]);
        }
    }
    refresh();
};

void ConsoleDraw::drawCharacter(Character &c) const{
    attron(COLOR_PAIR(Colors::DEFAULT));
    mvaddch(c.getPrevRow(), c.getPrevCol(), MapElements::EMPTY_SPACE);
    attroff(COLOR_PAIR(Colors::DEFAULT));

    attron(COLOR_PAIR(c.getColor()));
    mvaddch(c.getRow(), c.getCol(), c.getSprite());
    attroff(COLOR_PAIR(c.getColor()));
};

void ConsoleDraw::drawScore(unsigned int score){
    std::string score_str = std::to_string(score);
    for (std::string::size_type i = 0; i < score_str.size(); ++i){
        mvaddch(0, 8+i, score_str[i]);
    }
    refresh();
};

void ConsoleDraw::drawLives(unsigned int nLives){
    for (unsigned int i = 0; i < nLives; ++i){
        mvaddch(0, 24 + i, 'C');
    }
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
