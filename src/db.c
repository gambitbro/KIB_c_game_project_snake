#include <stdio.h>
#include <mysql.h>
#include <string.h>

int main(){
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char *host = "localhost";
    char *user = "root";
    char *passwd = "0000";
    char *db = "snakerecord";
    char query[255];
    int port = 3306;
    strcpy(query, "insert into record values(1, 집가고, 700, 10)");
    strcpy(query, "select * from record");

    conn = mysql_init(NULL);
    if(mysql_real_connect(conn, host, user, passwd, db, port, NULL, 0)){
        printf("MySQL 연결 성공\n");
    }else{
        printf("MySQL 연결 실패\n");
    }

    if(mysql_query(conn, query)){
        printf("쿼리 실패\n");
    }

    res = mysql_store_result(conn);
    while(row = mysql_fetch_row(res)){
        printf("%s\t", row[0]);
        printf("%s\t", row[1]);
        printf("%s\t", row[2]);
        printf("%s\t\n", row[3]);
    }
    mysql_close(conn);
    return 0;
}