#include <ncurses.h>

int main(int argc, char **argv)
{
    initscr();
    int height = 3;
    int width = 5;
    int starty = (LINES - height) / 2; /* Calculando para um posicionamento central */
    int startx = (COLS - width) / 2;   /* da janela */


    refresh();
    start_color(); /* Start color 			*/
    init_pair(1, COLOR_WHITE, COLOR_BLUE);

    WINDOW *win = newwin(height, width, starty, startx);
    wbkgd(win, COLOR_PAIR(1));

    mvwprintw(win, 0, 0, "  O O");
    mvwprintw(win, 2, 0, "VVVVV");
    wrefresh(win);
    int ch;
    int x=startx, y=starty;
    while ((ch = getch()) != 'q'){
        switch (ch){
        case 'a':
            --x;
            break;
        case 'd':
            ++x;
            break;
        case 'w':
            --y;
            break;
        case 's':
            ++y;
            break;
        }
        // wprintw(wn,"%c",ch);                                  //to check for input
        clear();
        refresh();

        wclear(win);
        mvwin(win, y, x);
        mvwprintw(win, 0, 0, "  O O");
        mvwprintw(win, 2, 0, "VVVVV");


        wrefresh(win);
        refresh();
    }
    refresh();
    endwin();
    return 0;
}