#include <ncurses.h>

#define WALL '_'

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
    int ch =0, x =0, y = 3;

    print_map();
    refresh();

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
        print_map();

        attron(COLOR_PAIR(1));
        mvaddch(y, x, pacman);
        attroff(COLOR_PAIR(1));
        move(y, x);
        // refresh();
    }

    endwin();
    return 0;
}