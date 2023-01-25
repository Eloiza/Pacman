#include <iostream>
#include "ConsoleDraw.hpp"
#include "Character.hpp"
#include "Colors.hpp"

using namespace gameColors;

int main(int argc, char **argv){
    ConsoleDraw console = ConsoleDraw();
    console.initNcurses(30,30);
    console.initColors();

    Character pacman('C',(unsigned int) Colors::PACMAN, 1, 2);

    unsigned char ch= ' ';
    while ((ch = getch()) != 'q'){
        pacman.move(ch);
        console.drawCharacter(pacman);
    }

    endwin();
    return 0;
}