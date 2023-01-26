#ifndef PACMAN_H
#define PACMAN_H

#include "Character.hpp"
#include "Colors.hpp"

class Pacman : public Character{
    public:
        Pacman();
        Pacman(char sprite, unsigned char y, unsigned char x);

        virtual ~Pacman() = default;

        virtual bool collision(unsigned char y, unsigned char x) override;

        /*getters*/
        unsigned int get_lives() const;
        unsigned int get_score() const;

        /*setters*/
        void set_lives(const unsigned int lives);
        void set_score(const unsigned int score);

    private:
        unsigned int score;
        unsigned int lives;
};

#endif