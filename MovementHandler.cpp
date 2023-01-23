#include "MovementHandler"

bool checkCollision(){

};

void move(unsigned char ch, unsigned int y, unsigned int x){
    int op;
    switch (ch){
    case 'a':
        op= -1;
        tst = x - 1;
        if (!collision(y, tst)){
            --x;
        }
        break;
    case 'd':
        tst = x + 1;
        if (!collision(y, tst))
        {
            ++x;
        }
        break;
    case 'w':
        tst = y - 1;
        if (!collision(tst, x))
        {
            --y;
        }
        break;

    case 's':
        tst = y + 1;
        if (!collision(tst, x))
        {
            ++y;
        }
        break;
    }
};
