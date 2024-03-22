#ifndef DB_H
#define DB_H
#include <mysql.h>

typedef struct {
  int userid;  
  char name[30];
  int point;
  int year;
  int month;
  int day;
  int hour;
  int min;
} RESULT;

void init_db();
void close_db();
void read_db();
void write_db(int userid, int point);

#endif