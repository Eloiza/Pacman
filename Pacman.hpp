#ifndef PACMAN_H
#define PACMAN_H

#include "Character.hpp"
#include "Colors.hpp"

class Pacman : public Character{
    public:
        Pacman();
        Pacman(unsigned int row, unsigned int col);

        virtual ~Pacman() = default;

        virtual bool isCollision(unsigned int row, unsigned int col) override;

        /*getters*/
        unsigned int getLives() const;
        unsigned int getScore() const;

        /*setters*/
        void setLives(const unsigned int lives);
        void setScore(const unsigned int score);

    private:
        unsigned int score;
        unsigned int lives;
};

#endif