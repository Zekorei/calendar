#ifndef _DATE_H
#define _DATE_H

typedef struct {
  int day;
  int month;
  int year;
} date_t;

date_t *create_date(int day, int month, int year);
date_t *current_date();
date_t *first_of_month(date_t *date);
void free_date(date_t *date);
int is_leap_year(date_t *date);

#endif
