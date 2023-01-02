#include "Coordenada.hpp"
#include "Pacman.hpp"

#include <iostream>
#include <string> 

int main(){    
    Coordenada c1;
    Coordenada c2(10,10);

    std::cout << "c1:" << c1.imprimir() << std::endl;
    std::cout << "c2:" << c2.imprimir() << std::endl;

    c1.setXY(1,1);
    std::cout << "c1:" << c1.imprimir() << std::endl;

    Coordenada c3 = c1 + c2;
    std::cout << "c3:" << c3.imprimir() << std::endl;

    c3 = c3 - c1;
    std::cout << "c3:" << c3.imprimir() << std::endl;

    c3 = c3 - 2;
    std::cout << "c3:" << c3.imprimir() << std::endl;

    c3++;
    std::cout << "c3:" << c3.imprimir() << std::endl;

    c3--;
    std::cout << "c3:" << c3.imprimir() << std::endl;

    std::cout << "c2 == c3: " << std::to_string(c2 == c3) << std::endl;
    std::cout << "c3 == c3: " << std::to_string(c3 == c3) << std::endl;

    return 0;
}