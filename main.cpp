#include <iostream>
#include <string>
#include <list>
// #include <chrono>

#include "ConsoleDraw.hpp"
#include "Colors.hpp"
#include "Pacman.hpp"
#include "Map.hpp"
#include "Ghost.hpp"
#include "Scatter.hpp"

#include "ChaseAggresive.hpp"
#include "ChaseAmbush.hpp"
#include "ChaseSiege.hpp"
#include "ChaseRandom.hpp"
#include "FrightenedBehavior.hpp"

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

    // //init pacman
    Pacman pacman(2, 1);

    // //init ghost
    Cell ghost_position = Cell(11, 15);
    Cell corner_positionA = Cell(23, 2);
    Cell corner_positionB = Cell(21, 9);

    ChaseAggresive pokey_bh = ChaseAggresive(&map, &ghost_position, pacman.getPosition());
    Scatter scatter_bh = Scatter(&map, &ghost_position, &corner_positionA, &corner_positionB);
    FrightenedBehavior frightened_bh = FrightenedBehavior(&map, &ghost_position);

    Ghost g1 = Ghost(&map, (unsigned int)11, (unsigned int) 15, &pokey_bh, &scatter_bh, &frightened_bh);
    unsigned char ch = ' ';
    
    //init clock
    using ms = std::chrono::duration<double, std::milli>;
    Clock ghostMoveClock = Clock();

    ghostMoveClock.start();
    g1.startClock();
    while ((ch = getch()) != 'q'){
        /*update pacman*/
        pacman.move(ch);
        console.drawCharacter(pacman);

        //update ghost position every 100ms
        if (ghostMoveClock.end() > (ms) 100.0){
            g1.move();
            ghostMoveClock.start();
        }

        g1.updateBehavior();
        console.drawCharacter(g1);
    }
    endwin();
    return 0;
}