#include <iostream>
#include <string>
#include <list>

#include "ConsoleDraw.hpp"
#include "Colors.hpp"
#include "Pacman.hpp"
#include "Map.hpp"

#include "Blinky.hpp"
#include "Pinky.hpp"
#include "Inky.hpp"
#include "Clyde.hpp"

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
    Pacman pacman(15, 13);

    //init ghost
    Blinky blinky = Blinky(&map, pacman.getPosition());
    Pinky pinky = Pinky(&map, pacman.getPosition());
    Inky inky = Inky(&map, pacman.getPosition(), blinky.getPosition());
    Clyde clyde = Clyde(&map, pacman.getPosition());

    unsigned char ch = ' ';

    //init clock
    using ms = std::chrono::duration<double, std::milli>;
    Clock ghostMoveClock = Clock();

    std::list<Ghost *> ghost_list;
    ghost_list.push_back(&blinky);
    ghost_list.push_back(&pinky);
    ghost_list.push_back(&inky);
    ghost_list.push_back(&clyde);

    CharacterCollisionController charCollision = CharacterCollisionController(&pacman, ghost_list);

    ghostMoveClock.start();
    std::list<Ghost *>::iterator ghost = ghost_list.begin();
    for(; ghost != ghost_list.end(); ghost++){
        (*ghost)->startClock();
    }
    while ((ch = getch()) != 'q' && !pacman.isDead()){
        if (!charCollision.checkCollisions()){
            /*update pacman*/
            pacman.move(ch);
            // update ghost position every 100ms
            if (ghostMoveClock.end() > (ms)160.0){
                for (ghost = ghost_list.begin(); ghost != ghost_list.end(); ghost++)
                    (*ghost)->move(pacman.isInvencible());
                ghostMoveClock.start();
            }
            pacman.updateState();

            for (ghost = ghost_list.begin(); ghost != ghost_list.end(); ghost++)
                (*ghost)->updateBehavior(pacman.isInvencible());
        }

        for (ghost = ghost_list.begin(); ghost != ghost_list.end(); ghost++)
            console.drawCharacter(**ghost);

        console.drawCharacter(pacman);
        console.drawHeader(pacman.getScore(), pacman.getLives());
    }
    endwin();
    return 0;
}