#ifndef _CALENDAR_C
#define _CALENDAR_C

#include<math.h>
#include<stdio.h>
#include<string.h>

#include"calendar.h"
#include"date.h"

int day_of_week(date_t *date) {
  int k = date->day;                                             // date of the month
  int m = (date->month + 10) % 12 + (date->month == 2 ? 12 : 0); // the month with March = 1
  int C = date->year / 100;                                      // century
  int Y = date->year % 100 - (date->month <= 2 ? 1 : 0);         // year in the century

  return (k + (int)floor(2.6F*(float)m - 0.2F) + 5*C + Y + Y/4 + C/4) % 7;
}

void print_calendar(date_t *date) {
  date_t *first;
  char title[CALENDAR_WIDTH];
  int padding, dow, current_dow;
  char *color;

  char *month_s = int_to_month[date->month-1];
  int days = int_to_days[date->month] + (date->month == 2 ? 1 : 0);
  snprintf(title, CALENDAR_WIDTH, "%s %d", month_s, date->year);

  // print header
  padding = (CALENDAR_WIDTH - strlen(title)) / 2;
  printf("%*c%s %d\n", padding, ' ', month_s, date->year);
  printf(DOW_HEADER "\n");

  // print body
  first = first_of_month(date);
  dow = day_of_week(first);
  free_date(first);
  printf("%*c", DAY_WIDTH*dow, ' ');
  for (int current_day = 1; current_day <= days; current_day++) {
    current_dow = (current_day + dow) % 7;
    color = (current_dow <= 1 ? C_LBLUE : NULL);
    color = (current_day == date->day ? C_BOLD C_LBLUE : color);
    cprint_day(current_day, color);

    if (current_dow == 0)
      printf("\n");
  }
  if (current_dow != 0)
    printf("\n");
}

void cprint_day(int day, char *color) {
  if (color == NULL)
    printf(DAY_FORMAT, DAY_WIDTH, day);
  else
    printf("%s" DAY_FORMAT C_END, color, DAY_WIDTH, day);
}

#endif

