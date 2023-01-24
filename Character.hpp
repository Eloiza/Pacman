#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <ncurses.h>

class Character{
    public:
        /*constructors*/
        Character();
        Character(char sprite, unsigned char color_pair, unsigned char y, unsigned char x);
        Character(char sprite, unsigned char y, unsigned char x);
        Character(char sprite);

        virtual ~Character() = default;
        void move(unsigned char direction);
        bool collision(unsigned char y, unsigned char x);
        
        /*setters*/
        void set_position(unsigned char y, unsigned char x);
        void set_x(unsigned x);
        void set_y(unsigned x);

        /*getters*/

    private:
        char sprite;
        bool state;
        unsigned char color_pair;
        unsigned char x;
        unsigned char y;
};
#endif