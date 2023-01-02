#ifndef COORDENADA_H
#define COORDENADA_H

#include <string>

class Coordenada{
    public:
        //construtores
        Coordenada(unsigned short const x, unsigned short const y);
        Coordenada();

        // destrutor
        ~Coordenada() = default;

        Coordenada operator + (Coordenada const &c) const;
        Coordenada operator + (short int const v) const;
        void operator ++(int);

        Coordenada operator - (Coordenada const &c) const;
        Coordenada operator - (short int const v) const;
        void operator --(int);

        bool operator==(Coordenada const &c) const;

        //setters
        void setX(unsigned short const x);
        void setY(unsigned short const y);
        void setXY(unsigned short const x, unsigned short const y);

        //getters
        unsigned short getX() const;
        unsigned short getY() const;

        std::string imprimir() const;

    private:
        unsigned short x;
        unsigned short y;
};

#endif