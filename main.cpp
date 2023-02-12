#include <iostream>
#include <string>
#include <list>

#include "ConsoleDraw.hpp"
#include "Colors.hpp"
#include "Pacman.hpp"
#include "Map.hpp"

#include "Blinky.hpp"
#include "CharacterCollisionController.hpp"
#include "Clock.hpp"
using namespace gameColors;


int main(int argc, char **argv){
    /*init game map*/
    Map map;
    map.loadGameMap("./maps/map.txt");

    /*init ncurses and console*/
    ConsoleDraw console = ConsoleDraw();
    console.initNcurses(40,40);
    console.initColors();
    console.drawGameScreen(&map);
    console.setMap(&map);
    //init pacman
    Pacman pacman(2, 1);

    //init ghost
    Blinky blinky = Blinky(&map, pacman.getPosition());
    unsigned char ch = ' ';
    
    //init clock
    using ms = std::chrono::duration<double, std::milli>;
    Clock ghostMoveClock = Clock();

    std::list<Ghost *> ghost_list;
    ghost_list.push_back(&blinky);
    CharacterCollisionController charCollision = CharacterCollisionController(&pacman, ghost_list);

    ghostMoveClock.start();
    blinky.startClock();
    while ((ch = getch()) != 'q' && !pacman.isDead()){
        if (!charCollision.checkCollisions()){
            /*update pacman*/
            pacman.move(ch);
            // update ghost position every 100ms
            if (ghostMoveClock.end() > (ms)160.0){
                blinky.move(pacman.isInvencible());
                ghostMoveClock.start();
            }
            pacman.updateState();
            blinky.updateBehavior(pacman.isInvencible());
        }

        console.drawCharacter(blinky);
        console.drawCharacter(pacman);
        console.drawHeader(pacman.getScore(), pacman.getLives());
    }
    endwin();
    return 0;
}