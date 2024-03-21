/**
 * printf, scanf, system함수를 사용하게 위해 불러온 헤더파일의 목록입니다.
*/
#include <stdio.h>
#include <stdlib.h>

int display_menu()
{
    int menu;

    system("clear");

    printf("-------------------\n");
    printf("Snake mbg\n");
    printf("-------------------\n");
    printf("\t\tGAME MENU\n");
    printf("-------------------\n");
    printf("1. Game Start\n");
    printf("2. Record\n");
    printf("3. Quit\n");
    printf("-------------------\n");

    
    scanf("%d", &menu);
    return menu;
}