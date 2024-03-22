#include <stdio.h>
#include <stdlib.h>
extern int point;
extern int count;
int display_menu();

int record()
{
    FILE *file_ptr;
    char name[50];
    point;
    count;

    printf("what is your name? :");
    scanf("%s",name);

    file_ptr = fopen("db.txt","w");

    if (file_ptr == NULL){
        printf("cannot open file\n");
        return 1;
    }

    fclose(file_ptr);
    printf("Fin");
    return 0;
}

int display_record()
{
    system("clear");
    int record;

    FILE *file_ptr;
    file_ptr = fopen("db.txt","r");

    if (file_ptr == NULL){
        printf("cannot open file\n");
        return 1;
    }

    while(fgets(point, sizeof(point), file_ptr) != NULL){
        printf("%d",point);
    }
    printf("back : 1");
    scanf("%d", &record);

    if (record == 1){
        fclose(file_ptr);
        record = display_menu;
    }

    return 0;
}