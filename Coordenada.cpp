#include "Coordenada.hpp"

// construtores
Coordenada::Coordenada(unsigned short x, unsigned short y): x{x}, y{y}{
};

Coordenada::Coordenada(): x{0}, y{0}{
};

// setters
void Coordenada::setX(unsigned short x){
    this->x = x;
};

void Coordenada::setY(unsigned short y){
    this->y = y;
};

void Coordenada::setXY(unsigned short x, unsigned short y){
    this->x = x;
    this->y = y;
};

// getters
unsigned short Coordenada::getX(){
    return this->x;
};

unsigned short Coordenada::getY(){
    return this->y;
};

std::string Coordenada::imprimir(){
    std::string coordString = "(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ")";
    return coordString;
};
