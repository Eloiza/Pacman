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

void printMap(Map * gameMap){
    unsigned int i, j;
    for (i = 0; i < gameMap->rows; i++){
        for (j = 0; j < gameMap->cols; j++)
        {
            std::cout << gameMap->map[i * gameMap->cols + j];
        }
        std::cout << std::endl;
    }
}

void move_ghost(Map * map, Ghost g, char c){
    map->map[g.previousPosition.x * (unsigned int)map->cols + g.previousPosition.y] = ' ';
    map->map[g.position.x * (unsigned int)map->cols +g.position.y] = c;
}

int main(int argc, char **argv){
    Map map;
    map.loadGameMap("./maps/map.txt");

    ConsoleDraw console = ConsoleDraw();
    console.initNcurses(40,40);
    console.initColors();
    console.drawGameScreen(&map);

    //init pacman 
    Pacman pacman('C', 2, 12);
    
    //init ghost
    Ghost g(Node(2, 1));
    move_ghost(&map, g, 'W');
    Node goal = Node(2, 12);
    Node result;

    unsigned char ch= ' ';
    while ((ch = getch()) != 'q'){
        pacman.move(ch);
        console.drawCharacter(pacman);

        result = g.generateDirection(&map, goal);
        g.move(result);
        console.drawCharacter(g);
    }
    endwin();
    return 0;
}