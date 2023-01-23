#include <ncurses.h>

#define WALL '_'

int collision(int y, int x)
{
    int testch;
    testch = mvinch(y, x);
    return (((testch & A_CHARTEXT) == '_') || ((testch & A_CHARTEXT) == '|'));
}

void print_map(){
    int y;
    attron(COLOR_PAIR(2));
    box(stdscr, 0, 0);

    // for (y = 0; y < LINES; y++){
    //         // mvhline(y, 0, WALL, 5);
    // }
    attroff(COLOR_PAIR(2));
};

int main(int argc, char **argv)
{
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    curs_set(FALSE); //hide cursor
    resizeterm(30, 30);

    start_color(); 
    wattron(stdscr, A_BOLD);

    init_pair(1, COLOR_YELLOW, COLOR_YELLOW); //pacman-color
    // init_pair(2, COLOR_BLACK, COLOR_BLUE); //maze-color
    init_pair(2, COLOR_BLUE, COLOR_BLACK); // maze-color

    char pacman = 'C';
    int ch =0, x =1, y = 1, tst=0;

    // print_map();

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
        erase();
        attron(COLOR_PAIR(1));
        mvaddch(y, x, pacman);
        attroff(COLOR_PAIR(1));
        move(y, x);
        mvaddch(10, 10, '|');
        mvaddch(10, 11, '|');

        // refresh();
    }

    endwin();
    return 0;
}