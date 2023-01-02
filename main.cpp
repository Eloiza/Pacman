#include "Coordenada.hpp"
#include "Pacman.hpp"

#include <iostream>
#include <string> 

int main(){
    Pacman p;
    p.mover('w');
    std::cout << "Movimento para cima: " << p.getPosicao()->imprimir() << std::endl;

    p.mover('a');
    std::cout << "Movimento para esquerda: " << p.getPosicao()->imprimir() << std::endl;

    p.mover('s');
    std::cout << "Movimento para baixo: " << p.getPosicao()->imprimir() << std::endl;
    
    p.mover('d');
    std::cout << "Movimento para direita: " << p.getPosicao()->imprimir() << std::endl;

    return 0;
}