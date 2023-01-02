#include "Coordenada.hpp"

// construtores
Coordenada::Coordenada(unsigned short const x, unsigned short const y): x{x}, y{y}{
};

Coordenada::Coordenada(): x{0}, y{0}{
};

Coordenada Coordenada::operator+(Coordenada const &c) const{
    Coordenada res(this->x + c.getX(), this->y + c.getY());
    return res;
};

Coordenada Coordenada::operator+(short int const v) const{
    Coordenada res(this->x + v, this->y + v);
    return res;
};

void Coordenada::operator++(int){
    this->x++; 
    this->y++;
};

Coordenada Coordenada::operator-(Coordenada const &c) const{
    Coordenada res(this->x - c.getX(), this->y - c.getY());
    return res;
};

Coordenada Coordenada::operator-(short int const v) const{
    Coordenada res(this->x - v, this->y - v);
    return res;
};

void Coordenada::operator--(int){
    this->x--;
    this->y--;
};

void Coordenada::operator=(Coordenada const &c){
    this->x = c.getX();
    this->y = c.getY();
};

bool Coordenada::operator==(Coordenada const &c) const{
    if(this->x == c.x && this->y == c.y)
        return 1;

    return 0;
};

// setters
void Coordenada::setX(unsigned short const x){
    this->x = x;
};

void Coordenada::setY(unsigned short const y){
    this->y = y;
};

void Coordenada::setXY(unsigned short const x, unsigned short const y){
    this->x = x;
    this->y = y;
};

// getters
unsigned short Coordenada::getX() const{
    return this->x;
};

unsigned short Coordenada::getY() const{
    return this->y;
};

std::string Coordenada::imprimir() const{
    std::string coordString = "(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ")";
    return coordString;
};
