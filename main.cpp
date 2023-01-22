#include <ncurses.h>

int main(int argc, char **argv)
{
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    curs_set(FALSE); //hide cursor

    start_color(); 
    wattron(stdscr, A_BOLD);
    init_pair(1, COLOR_YELLOW, COLOR_YELLOW);

    char pacman = 'C';
    int ch =0, x =0, y = 0;

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
        erase();
        attron(COLOR_PAIR(1));
        mvaddch(y, x, pacman);
        attroff(COLOR_PAIR(1));
        move(y, x);
        refresh();
    }

    endwin();
    return 0;
}