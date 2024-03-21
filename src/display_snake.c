#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <time.h>


#define width 40
#define height 30

extern int x;
extern int y;
extern int baitX;
extern int baitY;
extern int entireTail;
extern int point;

int snakeTailX[100];
int snakeTailY[100];

void display_snake()
{
    system("clear");

    //ceiling print
    for (int i = 0; i < width; ++i){
        for (int j = 0; j < height; ++j){
            if (i == 0 || i ==width-1)
            {
                printf("@");
            }else if (j == 0 || j == height -1)
            {
                printf("@");
            }
            else printf(" ");
        
            if (i == x && j == y){
                printf("O");
            } else if (i == baitX && j == baitY){
                printf("P");
            } else{
                int snakeTail = 0;
                for (int k = 0; k < entireTail; ++k){
                    if (snakeTailX[k] == i && snakeTailY[k] == j){
                        printf("o");
                        snakeTail = 1;
                    }
                }
                if (snakeTail == 0){
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("\n\n");
    printf("Your Point : %d\n", point);
}