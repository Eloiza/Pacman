#include "Coordenada.hpp"

// construtores
Coordenada::Coordenada(unsigned short x, unsigned short y): x{x}, y{y}{
};

Coordenada::Coordenada(): x{0}, y{0}{
};

Coordenada Coordenada::operator+(Coordenada c){
    Coordenada res(this->x + c.getX(), this->y + c.getY());
    return res;
};

Coordenada Coordenada::operator+(short int v){
    Coordenada res(this->x + v, this->y + v);
    return res;
};

void Coordenada::operator++(int v){
    this->x++; 
    this->y++;
};

Coordenada Coordenada::operator-(Coordenada c){
    Coordenada res(this->x - c.getX(), this->y - c.getY());
    return res;
};

Coordenada Coordenada::operator-(short int v){
    Coordenada res(this->x - v, this->y - v);
    return res;
};

void Coordenada::operator--(int v){
    this->x--;
    this->y--;
};

bool Coordenada::operator==(Coordenada c){
    if(this->x == c.x && this->y == c.y)
        return 1;

    return 0;
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
