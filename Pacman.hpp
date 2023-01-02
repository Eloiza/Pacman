#ifndef PACMAN_H
#define PACMAN_H

#include "Coordenada.hpp"

class Pacman{
    public:
        Pacman();
        virtual ~Pacman() = default;

        //getters
        const Coordenada* getPosicao() const;

        //setters
        void setPosicao(Coordenada const &c);
        void setPosicao(short int const x, short int const y);

        //movimento
        void mover(char const direcao);

    private:
        Coordenada* posicao;
        static char simbolo; 
};

#endif