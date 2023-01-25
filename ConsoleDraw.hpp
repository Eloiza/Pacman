#ifndef CONSOLE_DRAW_H
#define CONSOLE_DRAW_H

#include <ncurses.h>
#include <string>
#include <fstream>

#include "Character.hpp"

class ConsoleDraw{
    public:
        void initNcurses(int terminalWidth, int terminalHeight);
        void initColors();
        void drawGameScreen();
        void endNcurses();
        
        void loadGameMap(const std::string& fileName);

        void drawCharacter(Character& c) const;
        void drawCharacter(const unsigned char ch) const;
        void drawCharacter(const unsigned char ch, const int y, const int x) const;
        void drawCharacter(const unsigned char ch, const int y, const int x, const unsigned char color) const;

        /*getters*/
        void getTerminalSize(const int * width, const int * height) const;
        int getTerminalWidth() const;
        int getTerminalHeight() const;
        std::string getGameMap() const;
        int getmapCol();
        int getmapLin();

                /*setters*/
        void setTerminalSize(int width, int height);
        void setTerminalWidth(int width);
        void setTerminalHeight(int height);
        void setGameMap(std::string gameMap, unsigned char mapLin, unsigned char mapCol);

    private:
        int terminalWidth;
        int terminalHeight;
        std::string gameMap;
        unsigned char mapLin;
        unsigned char mapCol;
};

#endif