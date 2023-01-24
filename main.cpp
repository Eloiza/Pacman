#include "ConsoleDraw.hpp"
#include "Character.hpp"

int main(int argc, char **argv){
    ConsoleDraw console = ConsoleDraw();
    console.initNcurses(30,30);
    console.initColors();

    Character pacman('C', 1, 1, 2);

    unsigned char ch= ' ';
    while ((ch = getch()) != 'q'){
        pacman.move(ch);
        console.drawCharacter(pacman);
    }

    endwin();
    return 0;
}