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

#include "Clock.hpp"
using namespace gameColors;


int main(int argc, char **argv){
    /*init game map*/
    Map map;
    map.loadGameMap("./maps/map.txt");

    /*init ncurses and console*/
    // ConsoleDraw console = ConsoleDraw();
    // console.initNcurses(40,40);
    // console.initColors();
    // console.drawGameScreen(&map);

    // //init pacman
    // Pacman pacman(2, 1);

    // //init ghost
    // Cell ghost_position = Cell(11, 15);
    // Cell corner_positionA = Cell(23, 2);
    // Cell corner_positionB = Cell(21, 9);

    // // ChaseRandom pokey_bh = ChaseRandom(&map, &ghost_position, pacman.getPosition());
    // // Ghost g1 = Ghost(11, 15, &pokey_bh);

    // Scatter scatter_bh = Scatter(&map, &ghost_position, &corner_positionA, &corner_positionB);
    // Ghost g1 = Ghost(11, 15, &scatter_bh);

    // unsigned char ch = ' ';
    
    // //init clock
    // using ms = std::chrono::duration<double, std::milli>;
    // Clock ghostMoveClock = Clock();
    // Clock ghostBehaviorClock = Clock();

    // ghostMoveClock.start();
    // ghostBehaviorClock.start();
    // while ((ch = getch()) != 'q'){
    //     /*update pacman*/
    //     pacman.move(ch);
    //     console.drawCharacter(pacman);

    //     //update ghost position every 100ms
    //     if (ghostMoveClock.end() > (ms) 100.0){
    //         g1.move();
    //         ghostMoveClock.start();
    //     }

    //     //update ghost behavior every 7s
    //     g1.updateBehavior();
    //     console.drawCharacter(g1);
    // }
    // endwin();
    return 0;
}