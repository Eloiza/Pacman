#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <ncurses.h>

class Character{
    public:
        void move(unsigned char direction);
        bool collision(unsigned char y, unsigned char x);
        void set_position(unsigned char y, unsigned char x);
        
    private:
        char sprite;
        bool state;
        unsigned char color_pair;
        unsigned char x;
        unsigned char y;
};
#endif