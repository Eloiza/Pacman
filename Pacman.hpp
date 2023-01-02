#include "Coordenada.hpp"

class Pacman{
    public:
        Pacman();
        ~Pacman();

        //getters
        Coordenada* getPosicao();

        //setters
        setPosicao(Coordenada c);
        
    private:
        Coordenada* posicao;
        static char simbolo; 
}