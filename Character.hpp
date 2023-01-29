#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <ncurses.h>
#include "MapElements.hpp"
#include "Cell.hpp"

class Character{
    public:
        /*constructors*/
        Character();
        Character(char sprite, unsigned int color, unsigned int row, unsigned int col);
        Character(char sprite, unsigned int row, unsigned int col);

        Character(char sprite, unsigned int color_pair, Cell * const position);
        Character(char sprite, Cell * const  position);

        /*destructors*/
        virtual ~Character() = default;

        /*class methods*/
        virtual void move(unsigned int direction);
        virtual void move(Cell * const new_position);

        virtual bool isCollision(unsigned int row, unsigned int col);
        virtual bool isCollision(Cell * const position);

        /*setters*/
        void setPosition(unsigned int row, unsigned int col);
        void setPosition(Cell * const position);

        void setRow(unsigned int row);
        void setCol(unsigned int col);

        void setSprite(unsigned int sprite);
        void setColor(unsigned int color);

        void setPrevPosition(unsigned int row, unsigned int col);
        void setPrevPosition(Cell * const position);

        void setPrevRow(unsigned int row);
        void setPrevCol(unsigned int col);

        /*getters*/
        char getSprite();
        unsigned int getColor();
        unsigned int getRow();
        unsigned int getCol();
        unsigned int getPrevRow();
        unsigned int getPrevCol();

    protected:
        char sprite;
        unsigned int color;

        //store current position
        Cell position;

        // store previous position
        Cell prevPosition;

};
#endif