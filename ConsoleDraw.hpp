#ifndef CONSOLE_DRAW_H
#define CONSOLE_DRAW_H

#include <ncurses.h>
#include <string>

#include "Character.hpp"
#include "Map.hpp"

class ConsoleDraw{
    public:
        void initNcurses(int terminalWidth, int terminalHeight);
        void initColors();
        void ConsoleDraw::drawGameScreen(Map * gameMap);
        void endNcurses();
        
        void loadGameMap(const std::string& fileName);

        void drawScore(unsigned int score);
        void drawCharacter(Character& c) const;

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
};

#endif