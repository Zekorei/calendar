#include<stdio.h>

#include"calendar.h"
#include"date.h"

char *version = "1.2.0";

int main(int argc, char **argv) {
  date_t *today;

  if (argc == 1)
    today = current_date();
  else {
    printf("Command-line arguments are not supported yet\n");
    return 2;
  }

  if (today == NULL) {
    fprintf(stderr, "Unable to allocate memory\n");
    return 1;
  }

  // print calendar
  printf("Version %s\n", version);
  print_calendar(today);
  free_date(today);
  return 0;
}
