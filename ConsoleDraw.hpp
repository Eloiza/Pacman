#ifndef CONSOLE_DRAW_H
#define CONSOLE_DRAW_H

#include <ncurses.h>
#include <string>

#include "Character.hpp"
#include "Map.hpp"
#include "Ghost.hpp"

class ConsoleDraw{
    public:
        void initNcurses(int terminalWidth, int terminalHeight);
        void initColors();
        void endNcurses();

        void drawScore(unsigned int score);
        void drawLives(unsigned int nLives);
        void drawCharacter(Character& c) const;
        // void drawCharacter(Ghost &c) const;

        void drawGameScreen(Map * gameMap);

        /*getters*/
        void getTerminalSize(const int * width, const int * height) const;
        int getTerminalWidth() const;
        int getTerminalHeight() const;

                /*setters*/
        void setTerminalSize(int width, int height);
        void setTerminalWidth(int width);
        void setTerminalHeight(int height);

    private:
        int terminalWidth;
        int terminalHeight;
        Map * map;
};

#endif