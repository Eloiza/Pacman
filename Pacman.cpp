#include "Pacman.hpp"

char Pacman::simbolo{'<'};

Pacman::Pacman(): posicao{new Coordenada()}{
};

// getters
const Coordenada* Pacman::getPosicao() const{
    return this->posicao;
};

// setters
void Pacman::setPosicao(Coordenada const &c){
    *(this->posicao) = c;
};

void Pacman::setPosicao(short int const x, short int const y){
    this->posicao->setXY(x, y);
};

void Pacman::mover(char const direcao){
    switch(direcao){
        case 'w':
            this->setPosicao(this->posicao->getX(), this->posicao->getY() - 1);
            break;

        case 'a':
            this->setPosicao(this->posicao->getX() - 1, this->posicao->getY());
            break;
            
        case 's':
            this->setPosicao(this->posicao->getX(), this->posicao->getY() + 1);
            break;

        case 'd':
            this->setPosicao(this->posicao->getX() + 1, this->posicao->getY());
            break;
    }
};


