#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <time.h>

#define GAME_START 0
#define GAME_END 1
#define width 40
#define height 30
#define snake_init_length 3

int game;
int point = 0;
int x = width / 2;
int y = height / 2;
int entireTail;

extern int baitX();
extern int baitY();
extern sdir;

int update(int signum);
int display_menu();
void display_snake();

int game_start()
{
    // signal 설정
    static struct itimerval timer;
    signal(SIGVTALRM, update);
    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = 16667;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 16667;
    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    display_snake();
    while (1)
    {
        if (game == GAME_END)
        {
            // save_result(point);
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

    switch (menu)
    {
    case 1:
        game = GAME_START;
        reset();
        menu = game_start();
        break;
    case 2:
        printf("Record\n");
        // print_result();
        break;
    case 3:
        printf("Quit\n");
        break;
    }
    return 0;
}

void reset()
{
    // move_snake(STOP);
    point = 0;
    x = width / 2;
    y = height / 2;
    //    baitX = rand() % width;
    //    baitY = rand() % height;
}
