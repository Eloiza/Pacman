#ifndef CONSOLE_DRAW_H
#define CONSOLE_DRAW_H

#include <ncurses.h>

class ConsoleDraw{
    public:
        void initNcurses(int terminalWidth, int terminalHeight);
        void initColors();
        void drawGameScreen();
        void drawCharacter(const unsigned char ch, const int y, const int x, const unsigned char color) const;
        void endNcurses();

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