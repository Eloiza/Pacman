#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <bits/stdc++.h>

#include "ConsoleDraw.hpp"
#include "Character.hpp"
#include "Colors.hpp"
#include "Pacman.hpp"
#include "Node.hpp"
#include "Map.hpp"
#include "Ghost.hpp"

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
    Map map;
    map.loadGameMap("./maps/map.txt");

    ConsoleDraw console = ConsoleDraw();
    console.initNcurses(40,40);
    console.initColors();
    console.drawGameScreen(&map);

    //init pacman
    Pacman pacman(2, 1);

    //init ghost
    Cell nextPosition;
    std::list<Cell *> path;

    Ghost g(&map, 11, 15, pacman.getPosition());

    // std::list<Cell *>::iterator it = path.begin();
    // for(; it != path.end(); it++){
    //     std::cout << "(" <<(*it)->row << "," << (*it)->col << ")" << std::endl;
    // }
    
    unsigned char ch= ' ';
    unsigned int count = 0;
    unsigned int update_ghost = 0;
    unsigned int update_path = 0;

    while ((ch = getch()) != 'q'){
        pacman.move(ch);
        console.drawCharacter(pacman);

        if(count == 500){
            g.setTarget(pacman.getPosition());
            count = 0;
        }

        if(update_ghost == 4200){
            nextPosition = g.generateDirection();
            g.move(&nextPosition);
            napms(100);
            update_ghost = 0;
        }
        console.drawCharacter(g);

        update_ghost++;
        update_path++;
        count++;
    }
    endwin();
    return 0;
}