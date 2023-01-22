#include <ncurses.h>

int main(int argc, char **argv)
{
    initscr();
    noecho();
    // nodelay(stdscr, TRUE);

    int height = 3;
    int width = 5;
    int starty = (LINES - height) / 2; /* Calculando para um posicionamento central */
    int startx = (COLS - width) / 2;   /* da janela */

    start_color(); 
    wattron(stdscr, A_BOLD);
    init_pair(1, COLOR_WHITE, COLOR_BLUE);

    WINDOW *win = newwin(height, width, starty, startx);
    wbkgd(win, COLOR_PAIR(1));

    mvwprintw(win, 0, 0, "  O O     VVVVV");
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
        clear();
        refresh();

        wclear(win);
        mvwin(win, y, x);
        mvwprintw(win, 0, 0, "  O O     VVVVV");

        wrefresh(win);
        refresh();
    }
    refresh();
    endwin();
    return 0;
}