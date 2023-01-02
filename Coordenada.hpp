#ifndef COORDENADA_H
#define COORDENADA_H

#include <string>

class Coordenada{
    public:
        //construtores
        Coordenada(unsigned short x, unsigned short y);
        Coordenada();
        
        //destrutor
        ~Coordenada() = default;

        //setters
        void setX(unsigned short x);
        void setY(unsigned short y);
        void setXY(unsigned short x, unsigned short y);

        //getters
        unsigned short getX();
        unsigned short getY();

        std::string imprimir();

    private:
        unsigned short x;
        unsigned short y;
};

#endif