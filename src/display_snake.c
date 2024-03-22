#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <time.h>


#define width 40
#define height 40

extern int count;
extern int x;
extern int y;
extern int baitX;
extern int baitY;
extern int entireTail;
extern int point;
extern int snakeX[100];
extern int snakeY[100];


void display_snake()
{
    system("clear");
    //ceiling print
    for (int i = 0; i < height; ++i){
        for (int j = 0; j < width; ++j){
            for(int k = 0 ; k < entireTail; ++k){
                if (i == snakeX[k] && j == snakeY[k])
                    printf("🐍");
            }
            if (i == 0 || i == height -1){
                printf("@");
            }else if (j == 0 || j == width -1){ 
                printf("@");
            }else if (i == x && j == y){
                printf("🐍");
            } else if (i == baitX && j == baitY){
                printf("🍎");
            } 
            else printf(" ");
            
            
        }
        printf("\n");
    }
    printf("\n\n");
    printf("Your Point : %d\n", point);
    printf("\n\n");
    printf("Timer : %d\n",++count);
    printf("\n\n");
    printf("tail : %d\n",entireTail);
}