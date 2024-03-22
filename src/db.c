#include <stdio.h>
#include "db.h"
#include <string.h>


extern int point;

static MYSQL *conn = NULL;
static const char *host = "localhost";
static const char *user = "root";
static const char *passwd = "0000";
static const char *db = "snakerecord";
static const int port = 3306;

static RESULT tmp;

int print_result(MYSQL *conn) {
  MYSQL_RES *res;
  MYSQL_ROW row;
  res = mysql_store_result(conn);
  if (!res) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    return 1;
  }
  while ((row = mysql_fetch_row(res)) != NULL) {
    printf("%s\n", row[0]);
  }

  return 0;
}


void init_db() {
  // establish connection with mysql
  conn = mysql_init(NULL);
  // if connection failed
  if (!mysql_real_connect(conn, host, user, passwd, db, port, NULL, 0)) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    mysql_close(conn);
    exit(1);
  }

  create_table(conn);
}

void close_db() {
  if (conn != NULL) {
    mysql_close(conn);
  }
}


void read_db() {
  char query[256];
  printf("이름을 입력하세요: ");
  scanf("%s", tmp.name);
  snprintf(query, sizeof(query), "SELECT * FROM record WHERE name = '%s'", tmp.name);
  if (mysql_query(conn, query)) {
    printf("SELECT Query failed\n");
  }

  RESULT *res = get_one_row(conn);
  if (res == NULL) {
    system("clear");
    printf("********************************\n");
    printf("No History");
    printf("********************************\n");
  } else {
      system("clear");
      printf("********************************\n");
      printf("%s\n", res->name);
      printf("%d\n", res->point);
      printf("time: %d-%d-%d %d:%d\n", res->year, res->month, res->day, res->hour, res->min);
      printf("********************************\n");
  }
}

void write_db(int userid, int point) {
  printf("이름을 입력하세요: ");
  scanf("%s", tmp.name);

  tmp.point = point;

  time_t now_sec = time(NULL);
  struct tm *now = localtime(&now_sec);

  tmp.year = now->tm_year + 1900;
  tmp.month = now->tm_mon + 1;
  tmp.day = now->tm_mday;
  tmp.hour = now->tm_hour;
  tmp.min = now->tm_min;

  if (conn == NULL) {
    init_db();
  }

  char query[512];
  // safe version of printf
  // store query
  snprintf(query, sizeof(query),
           "INSERT INTO record (name, point, year, month, day, hour, min) VALUES "
           "('%s', %d, %d, %d, %d, %d, %d)",
           tmp.name, tmp.point, tmp.year, tmp.month, tmp.day, tmp.hour, tmp.min);
  if (mysql_query(conn, query)) {
    printf("INSERT Query failed: %s\n", mysql_error(conn));
  }
}