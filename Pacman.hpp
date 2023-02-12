#ifndef PACMAN_H
#define PACMAN_H

#include "Character.hpp"
#include "Colors.hpp"
#include "Clock.hpp"

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

        void activateInvencible();
        void deactivateInvencible();
        bool isInvencible();
        bool isDead();
        bool hasLostLive();
        void updateState();

    private:
        Clock stateClock;
        using ms = std::chrono::duration<double, std::milli>;
        ms invencibleDuration;

        unsigned int score;
        unsigned int lives;
        bool invencible;
        bool lostLive;
};

#endif