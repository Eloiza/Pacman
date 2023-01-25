#include "ConsoleDraw.hpp"
#include "Colors.hpp"

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
    // box(stdscr, 0, 0);
    // attron(COLOR_PAIR((short int) Colors::DEFAULT));
    int y = 0;
    mvhline(0, 1,'_', 40);
    mvhline(1, 1, '_', 40);

    mvaddch(1, 1, '|');
    // mvvline(1, 1, '|', 1);

    refresh();
    // for (y = 0; y < 30; y++){
    //     mvaddch(y, 30, '_');
    // }
    // attroff(COLOR_PAIR((short int) Colors::DEFAULT));
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
