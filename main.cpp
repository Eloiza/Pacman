#include <iostream>
#include <string>
#include <list>

#include "ConsoleDraw.hpp"
#include "Colors.hpp"
#include "Pacman.hpp"
#include "Map.hpp"
#include "Ghost.hpp"

#include "ScatterBehavior.hpp"

#include "ChaseAggresive.hpp"
#include "ChaseAmbush.hpp"
#include "ChaseSiege.hpp"
#include "ChaseRandom.hpp"

using namespace gameColors;

// void printMap(Map * gameMap){
//     unsigned int i, j;
//     for (i = 0; i < gameMap->rows; i++){
//         for (j = 0; j < gameMap->cols; j++)
//         {
//             std::cout << gameMap->map[i * gameMap->cols + j];
//         }
//         std::cout << std::endl;
//     }
// }

// void move_ghost(Map * map, Ghost g, char c){
//     map->map[g.previousPosition.x * (unsigned int)map->cols + g.previousPosition.y] = ' ';
//     map->map[g.position.x * (unsigned int)map->cols +g.position.y] = c;
// }

int main(int argc, char **argv){
    /*init game map*/
    Map map;
    map.loadGameMap("./maps/map.txt");
    // std::cout << g.getPosition()->row << "," << g.getPosition()->col << std::endl;
    // g.move();
    // std::cout << g.getPosition()->row << "," << g.getPosition()->col << std::endl;

    // g.move();
    // std::cout << g.getPosition()->row << "," << g.getPosition()->col << std::endl;

    // RandomBehavior random_bh = RandomBehavior(&map, &ghost_position);
    // g.setBehavior(&random_bh);
    // std::cout << "Setted Random Behavior" << std::endl;

    // g.move();
    // std::cout << g.getPosition()->row << "," << g.getPosition()->col << std::endl;
    // g.move();
    // std::cout << g.getPosition()->row << "," << g.getPosition()->col << std::endl;

    // AmbushBehavior ambush_bh = AmbushBehavior(&map, &ghost_position, &pacman_position, 4);
    // g.setBehavior(&ambush_bh);
    // std::cout << "Setted Ambush Behavior" << std::endl;
    // g.move();
    // std::cout << g.getPosition()->row << "," << g.getPosition()->col << std::endl;
    // g.move();
    // std::cout << g.getPosition()->row << "," << g.getPosition()->col << std::endl;

    /*init ncurses and console*/
    ConsoleDraw console = ConsoleDraw();
    console.initNcurses(40,40);
    console.initColors();
    console.drawGameScreen(&map);

    //init pacman
    Pacman pacman(2, 1);

    //init ghost
    Cell ghost_position = Cell(11, 15);
    Cell corner_positionA = Cell(23, 2);
    Cell corner_positionB = Cell(21, 9);

    ChaseRandom pokey_bh = ChaseRandom(&map, &ghost_position, pacman.getPosition());
    Ghost g1 = Ghost(11, 15, &pokey_bh);

    // Cell ghost_position2 = Cell(11, 15);

    // InkyBehavior inky_bh = InkyBehavior(&map, &ghost_position, pacman.getPosition(), &ghost_position2);
    // Ghost g1 = Ghost(11, 15, &inky_bh);

    // AmbushBehavior ambush_bh = AmbushBehavior(&map, &ghost_position2, pacman.getPosition(), 4);
    // Ghost g2 = Ghost(11, 14, &ambush_bh);

     unsigned char ch = ' ';
     unsigned int count = 0;
     unsigned int update_ghost = 0;
     unsigned int update_path = 0;

     while ((ch = getch()) != 'q')
     {
         pacman.move(ch);
         console.drawCharacter(pacman);

         if (update_ghost == 30200)
         {
             g1.move();
            //  g2.move();
            //  g3.move();
            //  g4.move();
             // napms(90);
             update_ghost = 0;
         }
         console.drawCharacter(g1);
        //  console.drawCharacter(g2);
        //  console.drawCharacter(g3);
        //  console.drawCharacter(g4);

         update_ghost++;
         update_path++;
         count++;
    }
    endwin();
    return 0;
}