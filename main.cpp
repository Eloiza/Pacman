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

double m_distance(Node p1, Node p2){
    /*implements manhathan distance*/
    return abs(p2.x - p1.x) + abs(p2.y - p1.y);
};

bool collision(std::string map, unsigned int x, unsigned int  y){
    return (map[x* (unsigned int) 28+y] == '#');
};

std::vector<Node> get_neighbors(std::string map, Node n){    
    unsigned int index;
    std::vector<Node> valid_neighbors;
    
    if (!collision(map, n.y, n.x + 1)){
        valid_neighbors.push_back(Node(n.x + 1, n.y));
    }
    if (!collision(map, n.y, n.x - 1))
    {
        valid_neighbors.push_back(Node(n.x + 1, n.y));
    }

    if (!collision(map, n.y + 1, n.x))
    {
        valid_neighbors.push_back(Node(n.x + 1, n.y));
    }
    if (!collision(map, n.y - 1, n.x))
    {
        valid_neighbors.push_back(Node(n.x + 1, n.y));
    }

    return valid_neighbors;
};

void a_star(Node start, Node goal, std::string map){
    // The set of discovered nodes that may need to be (re-)expanded.
    // Initially, only the start node is known.
    // This is usually implemented as a min-heap or priority queue rather than a hash-set.
    // openSet := {start}
    start.f = 0;
    std::vector<Node>openSet;
    openSet.push_back(start);

    // For node n, cameFrom[n] is the node immediately preceding it on the cheapest path from start
    // to n currently known.
    // cameFrom := an empty map
    std::vector<Node> cameFrom;

    // For node n, gScore[n] is the cost of the cheapest path from start to n currently known.
    // gScore := map with default value of Infinity
    // gScore[start] := 0
    start.g = 0;
    // std::vector<Node> gScore;
    // gScore.push_back(start);

    // For node n, fScore[n] := gScore[n] + h(n). fScore[n] represents our current best guess as to
    // how cheap a path could be from start to finish if it goes through n.
    start.f = start.g + m_distance(start, goal);

    // fScore := map with default value of Infinity
    // fScore[start] := h(start)
    // while openSet is not empty
    Node current;
    while(!openSet.empty()){
        sort(openSet.begin(), openSet.end());
        current = openSet[0];
        
        //check this after
        if(current == goal){
            //return the path 
            return;
        };
        openSet.erase(openSet.begin());
        std::vector<Node> neighbors = get_neighbors(map, current);

        std::vector<Node>::iterator neighbor;
        double tentative_gScore = 0;
        for(neighbor=neighbors.begin(); neighbor < neighbors.end(); neighbor++){
            //estimate the path cost if took previous path + estimate path
            tentative_gScore = current.g + m_distance(current, *neighbor);
            
            //found a better path
            if(tentative_gScore < (*neighbor).g){
                cameFrom.push_back(current);
                (*neighbor).g = tentative_gScore;
                (*neighbor).f = tentative_gScore + m_distance(*neighbor, goal);
                
                //check if neighbor is in openSet
                if (std::find(openSet.begin(), openSet.end(), neighbor) != openSet.end()){
                    openSet.push_back(*neighbor);
                }
            }
        }
    }
};
        // This operation can occur in O(Log(N)) time if openSet is a min-heap or a priority queue
//         current := the node in openSet having the lowest fScore[] value
//         if current = goal
//             return reconstruct_path(cameFrom, current)

//         openSet.Remove(current)
//         for each neighbor of current
//             // d(current,neighbor) is the weight of the edge from current to neighbor
//             // tentative_gScore is the distance from start to the neighbor through current
//             tentative_gScore := gScore[current] + d(current, neighbor)
//             if tentative_gScore < gScore[neighbor]
//                 // This path to neighbor is better than any previous one. Record it!
//                 cameFrom[neighbor] := current
//                 gScore[neighbor] := tentative_gScore
//                 fScore[neighbor] := tentative_gScore + h(neighbor)
//                 if neighbor not in openSet
//                     openSet.add(neighbor)

//     // Open set is empty but goal was never reached
//     return failure
// }

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