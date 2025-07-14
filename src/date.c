#ifndef _DATE_C
#define _DATE_C

#include<time.h>
#include<stdlib.h>

#include"date.h"

date_t *create_date(int day, int month, int year) {
  date_t *date;
  date = malloc(sizeof *date);
  if (date == NULL)
    return NULL;
  date->day = day;
  date->month = month;
  date->year = year;
  return date;
}

date_t *current_date() {
  time_t now = time(NULL);
  struct tm *t = localtime(&now);
  return create_date(t->tm_mday, t->tm_mon + 1, t->tm_year + 1900);
}

date_t *first_of_month(date_t *date) {
  return create_date(1, date->month, date->year);
}

void free_date(date_t *date) {
  free(date);
}


int is_leap_year(date_t *date) {
  char flag = 1;
  if (date->month != 2) flag = 0;

  if (date->year % 100 == 0) {
    if (date->year % 400 != 0) flag = 0;
    if (date->year % 4 != 0) flag = 0;
  }

  return flag;
}

#endif
