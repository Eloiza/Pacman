#include "Coordenada.hpp"

// construtores
Coordenada::Coordenada(signed char const x, signed char const y): x{x}, y{y}{
};

Coordenada::Coordenada(): x{0}, y{0}{
};

Coordenada Coordenada::operator+(Coordenada const &c) const{
    Coordenada res(this->x + c.getX(), this->y + c.getY());
    return res;
};

Coordenada Coordenada::operator+(signed char const v) const{
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

Coordenada Coordenada::operator-(signed char const v) const{
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
void Coordenada::setX(signed char const x){
    this->x = x;
};

void Coordenada::setY(signed char const y){
    this->y = y;
};

void Coordenada::setXY(signed char const x, signed char const y){
    this->x = x;
    this->y = y;
};

// getters
signed char Coordenada::getX() const{
    return this->x;
};

signed char Coordenada::getY() const{
    return this->y;
};

std::string Coordenada::imprimir() const{
    std::string coordString = "(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ")";
    return coordString;
};
