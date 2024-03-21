/**
 * @brief  printf, scanf, system함수를 사용하게 위해 불러온 헤더파일의 목록입니다.
*/
#include <stdio.h>
#include <stdlib.h>
/**
 * @brief 디스플레이 함수의 구성목록입니다. 정수형 변수인 menu와 게임의 제목과 메뉴의 
 * 구성요소들을 출력될수 있도록 했습니다. 
*/
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