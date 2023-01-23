#include "ConsoleDraw.hpp"

int collision(int y, int x){
    int testch;
    testch = mvinch(y, x);
    return (((testch & A_CHARTEXT) == '_') || ((testch & A_CHARTEXT) == '|'));
}

int main(int argc, char **argv)
{
    ConsoleDraw console = ConsoleDraw();
    console.initNcurses(30,30);
    console.initColors();

    char pacman = 'C';
    int ch =0, x =1, y = 1, tst=0;

    while ((ch = getch()) != 'q'){
        switch (ch){
        case 'a':
            tst = x-1;
            if (!collision(y, tst)){
                --x;
            }
            break;
        case 'd':
            tst = x+1;
            if (!collision(y, tst)){
                ++x;
            }
            break;
        case 'w':
            tst = y-1;
            if (!collision(tst, x)){
                --y;
            }
            break;

        case 's':
            tst = y+1;
            if (!collision(tst, x)){
                ++y;
            }
            break;
        }
        console.drawCharacter(pacman, y, x, 1);
    }

    endwin();
    return 0;
}