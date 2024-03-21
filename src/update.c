#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>

#define GAME_START 0
#define GAME_END 1
#define width 160
#define height 120

int baitX(void);
int baitY(void);

extern int x;
extern int y;
extern int game;
extern int point;
extern snakeTailX[100];
extern snakeTailY[100];
extern entireTail;

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

    switch (sdir)
    {
    case LEFT:
        newx--;
        break;
    case RIGHT:
        newx++;
        break;
    case DOWN:
        newy++;
        break;
    case UP:
        newy--;
        break;
    }

    return 0;
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

void update(void)
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

    // random bait setup
    if (x == baitX && y == baitY)
    {
        point += 10;
        baitY();
        baitX();
        ++entireTail;
    }

    // gameover if snake touch it's own body
    for (int i = 0; i < entireTail; ++i)
    {
        if (snakeTailX[i] == x && snakeTailY[i] == y)
        {
            game = GAME_END;
        }
    }

    // gameover if snake touch wall
    if (x >= width || x < 0 || y >= height || y < 0)
    {
        game = GAME_END;
    }

    
}

int baitY(void)
{
    int num;
    num = rand() % width;
    return baitY;
}

int baitX(void)
{
    int num;
    num = rand() % height;
    return baitX;
}