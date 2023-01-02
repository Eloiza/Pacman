#include "Coordenada.hpp"

#include <iostream>

int main(){    
    Coordenada c1;
    Coordenada c2(10,10);

    std::cout << "c1:" << c1.imprimir() << std::endl;
    std::cout << "c2:" << c2.imprimir() << std::endl;

    c2.setXY(32,1);
    std::cout << "c2:" << c2.imprimir() << std::endl;

    return 0;
}