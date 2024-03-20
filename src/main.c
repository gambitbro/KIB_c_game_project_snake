#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GAME_START 0
#define GAME_END 1
#define width 160
#define height 120
#define snake_init_length 3

int game;
int point = 0;
int x = width / 2;
int y = height / 2;
int entireTail;

extern int baitX = rand() % width;
extern int baitY = rand() % height;
extern sdir;


int update();
int display_menu();

int game_start()
{
    while (1){
        if (game == GAME_END){
            //save_result(point);
            reset();
            return 1;
        }
    }
    game = GAME_END;
}

int main(void)
{
    int menu = 1;
    menu = display_menu();

    switch(menu){
    case 1:
        game = GAME_START;
        reset();
        menu = game_start();
        break;
    case 2:
        printf("Record\n");
        //print_result();
        break;
    case 3:
        printf("Quit\n");
        break;
    }
    return 0;
}

void reset()
{
    point = 0;
    x = width / 2;
    y = height / 2;
    baitX = rand() % width;
    baitY = rand() % height; 
}
