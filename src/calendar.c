#ifndef _CALENDAR_C
#define _CALENDAR_C

#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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
  char title[CALENDAR_WIDTH];
  int padding, current_dow;
  char *color;

  char *month_s = int_to_month[date->month-1];
  int days = int_to_days[date->month] + (date->month == 2 ? 1 : 0);
  snprintf(title, CALENDAR_WIDTH, "%s %d", month_s, date->year);

  // print header
  padding = (CALENDAR_WIDTH - strlen(title)) / 2;
  printf("%*c%s %d\n", padding, ' ', month_s, date->year);
  printf(DOW_HEADER "\n");

  // print body
  date_t *first_day = first_of_month(date);
  int dow = day_of_week(first_day);
  free_date(first_day);

  for (int i = 0; i < dow*DAY_WIDTH; i++) {
    putchar(' ');
  }

  for (int current_day = 1; current_day <= days; current_day++) {
    fprintf(stderr, "current_day = %d\n", current_day);
    current_dow = (current_day + dow) % 7;
//     color = (current_dow <= 1 ? C_LBLUE : NULL);
    color = (current_day == date->day ? C_LBLUE : NULL);
    cprint_day(current_day, color);

    if (current_dow == 0)
      printf("\n");
  }
  if (current_dow != 0)
    printf("\n");
}

void cprint_day(int day, char *color) {
  if (color == NULL) {
    printf("%-*d", DAY_WIDTH, day);
  } else {
    size_t fday_buffer = strlen(color) + 20;
    char *fday = malloc(fday_buffer);

    if (fday == NULL) {
      fprintf(stderr, "cprint_day: malloc() error\n");
      return;
    }

    snprintf(fday, fday_buffer, "%s%d%s", color, day, C_END);
    int formatting_width = strlen(color) + strlen(C_END) + DAY_WIDTH;
    printf("%-*s", formatting_width, fday);
    free(fday);
  }
}

#endif
