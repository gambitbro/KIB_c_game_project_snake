/**
 * @brief 스네이크 게임의 필드 구성을 정의했습니다. 필드의 총 길이와 높이를 지정하였고
 * 메인함수에서 가져온 각종 필요한 변수들을 정의했습니다. 그리고 미끼를 먹었을때 늘어나는 꼬리의
 * 최대개수를 배열로 정의했습니다.(메인함수에서 가져온 함수들은 메인함수에서 따로 설명할것임.) 
 * */


#define width 160
#define height 120

extern int x;
extern int y;
extern int baitX;
extern int baitY;
extern int entireTail;
extern int point;

int snakeTailX[100];
int snakeTailY[100];
/**
* @brief display_snake(필드구성함수)를 정의했습니다
게임을 시작했을때 기존의 화면을 지우고 새로운 화면을 만들기 위한 system(clear)함수를 사용하였고 
게임 영역의 상단을 나타내는 '@' 문자들을 출력합니다.
또한 이중 루프를 사용하여 게임 영역의 각 셀을 반복하면서

    왼쪽 벽('@' 문자)을 출력합니다.
    현재 셀이 뱀의 머리인 경우 'O'를 출력합니다.
    현재 셀이 먹이인 경우 'P'를 출력합니다.
    그렇지 않은 경우:
        뱀 꼬리가 존재하는지 확인하고, 꼬리가 있는 경우 'o'를 출력합니다.
        꼬리가 없는 경우 빈 공간을 출력합니다.
    오른쪽 벽('@' 문자)을 출력합니다.
*/
void display_snake()
{
    system("clear");

    //ceiling print
    for (int i = 0; i < width + 2; ++i){
        printf("@");
    }
    printf("\n");

    for (int i = 0; i < width; ++i){
        for (int j = 0; j < height; ++j){
            if (j == 0){
                printf("@");
            }
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
            if (j == width - 1){
                printf("@");
            }
        }
        printf("\n");
    }
    for (int i = 0; i < width + 2; ++i){
        printf("@");
    }
    printf("\n\n");
    printf("Your Point : %d\n", point);
}