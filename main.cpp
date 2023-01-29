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

    Ghost g(Node(2, 1));
    Ghost p(Node(2, 12));
    move_ghost(&map, g, 'W');
    move_ghost(&map, p, 'C');
    printMap(&map);

    Node goal = Node(2,12);
    Node result;
    int troca = 0;
    std::cout << "Distance: " << g.distance(g.position, goal) << std::endl;

    for(int i=0; i<10; i++){
        result = g.generateDirection(&map, goal);

        g.move(result);
        std::cout << "Distance: " << g.distance(g.position, goal) << std::endl;
        std::cout << "Direction result: (" << result.x << ", " << result.y << ")" << std::endl;

        move_ghost(&map, g, 'W');
        move_ghost(&map, p, 'C');

        printMap(&map);
        std::cout << std::endl;
        std::cout << std::endl;
    }
    // std::cout << "Start position: (" << g.position.x << ", " << g.position.y << ")" << std::endl;
    // result = g.generateDirection(&map, goal);
    // g.move(result);
    // std::cout << "Direction result: (" << result.x << ", " << result.y << ")" << std::endl;
    // std::cout << "Move result: (" << g.position.x << ", " << g.position.y << ")" << std::endl;

    // std::cout << "Start position: (" << g.position.x << ", " << g.position.y << ")" << std::endl;
    // result = g.generateDirection(&map, goal);
    // g.move(result);
    // std::cout << "Direction result: (" << result.x << ", " << result.y << ")" << std::endl;
    // std::cout << "Move result: (" << g.position.x << ", " << g.position.y << ")" << std::endl;

    // std::cout << "Start position: (" << g.position.x << ", " << g.position.y << ")" << std::endl;
    // result = g.generateDirection(&map, goal);
    // g.move(result);
    // std::cout << "Direction result: (" << result.x << ", " << result.y << ")" << std::endl;
    // std::cout << "Move result: (" << g.position.x << ", " << g.position.y << ")" << std::endl;

    // while ((ch = getch()) != 'q'){
    //     pacman.move(ch);
    //     console.drawCharacter(pacman);
    //     result = g.generateDirection(&map, goal);
    //     g.move(result);
    //     console.drawCharacter(g);
    //     // console.drawScore((unsigned int) pacman.get_score());
    // }

    endwin();
    return 0;
}