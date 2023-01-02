#ifndef COORDENADA_H
#define COORDENADA_H

#include <string>

class Coordenada{
    public:
        //construtores
        Coordenada(signed char const x, signed char const y);
        Coordenada();

        // destrutor
        ~Coordenada() = default;

        Coordenada operator + (Coordenada const &c) const;
        Coordenada operator + (signed char const v) const;
        void operator ++(int);

        Coordenada operator - (Coordenada const &c) const;
        Coordenada operator - (signed char const v) const;
        void operator --(int);

        void operator= (Coordenada const &c);
        bool operator==(Coordenada const &c) const;

        //setters
        void setX(signed char const x);
        void setY(signed char const y);
        void setXY(signed char const x, signed char const y);

        //getters
        signed char getX() const;
        signed char getY() const;

        std::string imprimir() const;

    private:
        signed char x;
        signed char y;
};

#endif