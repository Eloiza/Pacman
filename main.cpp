#include "ConsoleDraw.hpp"
#include "Character.hpp"

int main(int argc, char **argv){
    ConsoleDraw console = ConsoleDraw();
    console.initNcurses(30,30);
    console.initColors();

    Character pacman('C', 1, 1);

    unsigned char ch= ' ';
    while ((ch = getch()) != 'q'){
        pacman.move(ch);
        console.drawCharacter(pacman.get_sprite(), pacman.get_y(), pacman.get_x(), pacman.get_color());
    }

    endwin();
    return 0;
}