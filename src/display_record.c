#include <stdio.h>
#include <stdlib.h>

int display_record()
{
    int record;

    system("clear");

    FILE = *file_ptr;
    file_ptr = fopen(db.txt,"r");
    if (file_prt == NULL){
        printf("cannot open file\n")
        return 1;
    }

    while(fgets(data, sizeof(data), file_ptr) != NULL){
        pritf("%s",data);
    }
    printf("back : 1");
    scanf("%d", &record);

    if (record == 1){
        fclose(file_ptr);
        record = display_menu
    }

    return 0;
}