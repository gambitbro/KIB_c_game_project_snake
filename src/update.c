#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>

#define GAME_START 0
#define GAME_END 1
#define width 40
#define height 30

int count;
extern int x;
extern int y;
extern int game;
extern int point;
extern snakeTailX[100];
extern snakeTailY[100];
extern entireTail;
extern int space();
int baitX;
int baitY;

typedef enum
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
} sdir;

int move_snake(int sdir)
{
    int newx, newy;

    newx = x;
    newy = y;

    switch (sdir){
        case LEFT:
            newy--;
            break;
        case RIGHT:
            newy++;
            break;
        case DOWN:
            newx++;
            break;
        case UP:
            newx--;
            break;
        default:
            break;
    }
    x = newx;
    y = newy;
    return 0;
}

// bait & snake
void collison()
{
    if (x == baitX && y == baitY)
    space();
}

// update snaketail
void update_snaketail()
{
    int oldX = snakeTailX[0];
    int oldY = snakeTailY[0];
    int oldX2, oldY2;
    snakeTailX[0] = x;
    snakeTailY[0] = y;
    for (int i = 1; i < entireTail; ++i)
    {
        oldX2 = snakeTailX[i];
        oldY2 = snakeTailY[i];
        snakeTailX[i] = oldX;
        snakeTailY[i] = oldY;
        oldX = oldX2;
        oldY = oldY2;
    }
}

int update(int signum)
{
    srand((unsigned)time(NULL));

    int ch;
    ch = getch();

    switch (ch)
    {
    case 'i':
        move_snake(UP);
        break;
    case 'j':
        move_snake(LEFT);
        break;
    case 'k':
        move_snake(DOWN);
        break;
    case 'l':
        move_snake(RIGHT);
        break;
    case 's':
        game = GAME_END;
        break;
    default:
        break;
    }

    ++ count;
    display_snake();
    update_snaketail();
    collison();
    // gameover if snake touch it's own body
    for (int i = 0; i < entireTail; ++i)
    {
        if (snakeTailX[i] == x && snakeTailY[i] == y)
        {
            game = GAME_END;
        }
    }

    // gameover if snake touch wall
    if (x == 0) game = GAME_END;
    if (y == 0) game = GAME_END;
    if (x == width) game = GAME_END;
    if (y == height) game = GAME_END;


int space()
{
    srand(time(NULL));
    baitX = rand() % width-1;
    baitY = rand() % height-1;
    return baitX , baitY;
}
}



