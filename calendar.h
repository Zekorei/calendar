#ifndef _CALENDAR_H
#define _CALENDAR_H

#include"date.h"

#define YEAR_MIN 1900
#define YEAR_MAX 3000
#define YEAR_LEN 4

#define DOW_HEADER "S  M  T  W  T  F  S"
#define CALENDAR_WIDTH 20
#define DAY_WIDTH 3
#define DAY_FORMAT "%-*d"

#define C_LBLUE "\033[1;34m"
#define C_UNDERLINE "\033[4m"
#define C_BOLD "\033[2m"
#define C_END "\033[0m"

static char * const int_to_month[] = {
  "January", "Feburary", "March", "April",
  "May", "June", "July", "August",
  "September", "October", "November", "December"
};

static int const int_to_days[] = {
  31, 28, 31, 30,
  31, 30, 31, 31,
  30, 31, 30, 31,
};

int day_of_week(date_t *date);
void print_calendar(date_t *date);
void cprint_day(int day, char *color);

#endif
