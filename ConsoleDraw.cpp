#include "ConsoleDraw.hpp"

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

    init_pair(1, COLOR_YELLOW, COLOR_YELLOW); // pacman-color
    init_pair(2, COLOR_BLUE, COLOR_BLACK); // maze-color
};

void ConsoleDraw::drawGameScreen(){
    attron(COLOR_PAIR(2));
    box(stdscr, 0, 0);
    // for (y = 0; y < LINES; y++){
    //         // mvhline(y, 0, WALL, 5);
    // }
    attroff(COLOR_PAIR(2));
};

void ConsoleDraw::drawCharacter(Character &c) const{
    erase();
    attron(COLOR_PAIR(c.get_color()));
    mvaddch(c.get_y(), c.get_x(), c.get_sprite());
    attroff(COLOR_PAIR(c.get_color()));
    move(c.get_y(), c.get_x());
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

void ConsoleDraw::getTerminalSize(const int *width, const int * height) const
{
    width = &this->terminalWidth;
    height = &this->terminalHeight;
};

int ConsoleDraw::getTerminalWidth() const{
    return this->terminalWidth;
};

int ConsoleDraw::getTerminalHeight() const{
    return this->terminalHeight;
};

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
