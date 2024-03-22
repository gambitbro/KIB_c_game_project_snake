/*

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
    return 0;
}