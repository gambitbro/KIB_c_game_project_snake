#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>

#define GAME_START 0
#define GAME_END 1
#define width 40
#define height 40

int count;
extern int x;
extern int y;
extern int game;
extern int point;
extern entireTail;

int baitX;
int baitY;
int snakeX[100];
int snakeY[100];

int record();

void space()
{
    srand(time(NULL));

    baitX = rand()%height-1;
    baitY = rand()%width-1;

    if(baitX == 0 || baitX == height)
    {baitX = rand()%height-1;}
    else if(baitY == 0 || baitY == width)
    {baitY = rand()%width-1;}
    
    if (x == baitX && y == baitY)
    {
        baitX = rand()%height-1;
        baitY = rand()%width-1;
    }
    
}

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
    }   

    x = newx;
    y = newy;

    return 0;
}

// bait & snake
void collison()
{
    if (x == baitX && y == baitY)
    {++point;
    ++entireTail;
    space();
    void update_snaketail();}
}

int update(int signum)
{
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
            record();
            break;
        
        }
    
    
    
    ++ count;
    display_snake();
    collison();
    // gameover if snake touch it's own body
    //for (int i = 1; i < entireTail; ++i)
   // {
        //if(snakeX[0]==snakeX[i] && snakeY[0]==snakeY[i])
        // game = GAME_END;
   // }
    

    // gameover if snake touch wall
    if (x == 0) game = GAME_END;
    if (y == 0) game = GAME_END;
    if (x == width-1) game = GAME_END;
    if (y == height-1) game = GAME_END;


    // snake tail logic
    int tempX = snakeX[0];
    int tempY = snakeY[0];
    int tempX2, tempY2;
    snakeX[0] = x;
    snakeY[0] = y;
    for (int i = 1; i < entireTail; i++) {
        tempX2 = snakeX[i];
        tempY2 = snakeY[i];
        snakeX[i] = tempX;
        snakeY[i] = tempY;
        tempX = tempX2;
        tempY = tempY2;
    }
    return 0;
}



