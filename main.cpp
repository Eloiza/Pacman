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
using namespace gameColors;

int main(int argc, char **argv){
    std::vector<Node> lista;

    lista.push_back(Node(1, 1, 1));
    lista.push_back(Node(10, 10, 0));
    lista.push_back(Node(2, 2, 2));
    std::cout << "Not sorted\n";
    for(unsigned int i=0; i<lista.size();i++){
        /*print like (x,y): f:f*/
        std::cout << "(" << lista[i].x << "," << lista[i].y << ")" 
        << ": f: " << lista[i].f << std::endl;
    }
    std::sort(lista.begin(), lista.end());
    std::cout << "Sorted\n";

    for (unsigned int i = 0; i < lista.size(); i++){
        /*print like (x,y): f:f*/
        std::cout << "(" << lista[i].x << "," << lista[i].y << ")"
                  << ": f: " << lista[i].f << std::endl;
    }
    // ConsoleDraw console = ConsoleDraw();
    // console.loadGameMap("./maps/map.txt");
    // console.initNcurses(40,40);
    // console.initColors();
    // console.drawGameScreen();

    // Pacman pacman('C', 2, 1);
    // unsigned char ch= ' ';
    // while ((ch = getch()) != 'q'){
    //     pacman.move(ch);
    //     console.drawCharacter(pacman);
    //     // console.drawScore((unsigned int) pacman.get_score());
    // }

    // endwin();
    // return 0;
}