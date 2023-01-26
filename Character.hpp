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

        /*destructors*/
        virtual ~Character() = default;

        /*class methods*/
        void move(unsigned char direction);
        bool collision(unsigned char y, unsigned char x);
        
        /*setters*/
        void set_position(unsigned char y, unsigned char x);
        void set_x(unsigned char x);
        void set_y(unsigned char y);
        void set_state(bool state);
        void set_sprite(unsigned char sprite);
        void set_color(unsigned char color);
        void set_prev_position(unsigned char y, unsigned char x);
        void set_prev_x(unsigned char x);
        void set_prev_y(unsigned char y);

        /*getters*/
        char get_sprite();
        bool get_state();
        unsigned char get_color();
        unsigned char get_x();
        unsigned char get_y();
        unsigned char get_prev_x();
        unsigned char get_prev_y();

    private:
        char sprite;
        bool state;
        unsigned char color_pair;
        unsigned char x;
        unsigned char y;

        //store previous position
        unsigned char prev_x;
        unsigned char prev_y;
};
#endif