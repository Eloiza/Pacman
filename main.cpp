#include <iostream>
#include <fstream>
#include <string>

#include "ConsoleDraw.hpp"
#include "Character.hpp"
#include "Colors.hpp"
#include "Pacman.hpp"

using namespace gameColors;

int main(int argc, char **argv){
    ConsoleDraw console = ConsoleDraw();
    console.loadGameMap("./maps/map.txt");
    console.initNcurses(40,40);
    console.initColors();
    console.drawGameScreen();

    Pacman pacman('C', 2, 1);
    unsigned char ch= ' ';
    while ((ch = getch()) != 'q'){
        pacman.move(ch);
        console.drawCharacter(pacman);
        console.drawScore((unsigned int) pacman.get_score());
    }

    endwin();
    return 0;
}