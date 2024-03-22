/**
 * @file:display_menu.c
 * @brief printf, scanf, system함수를 사용하기 위해 불러온
 * 헤더파일들입니다.
*/

#include <stdio.h>
#include <stdlib.h>
/**
 * @brief display_menu함수는 menu변수를 정의하고 화면을 초기하고
 * 게임메뉴들을 표시해주는 함수입니다.
*/
int display_menu()
{
    int menu;

    system("clear");


    printf("--------------------\n");
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