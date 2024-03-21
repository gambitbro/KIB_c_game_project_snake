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
게임을 시작했을때
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