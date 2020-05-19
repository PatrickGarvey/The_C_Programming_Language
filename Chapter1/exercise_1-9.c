#include <stdio.h>


int main()
{

  int c, blank_counter;

  blank_counter = 0;

  while ((c = getchar()) != EOF) {
    if ((c == ' ') && (blank_counter == 0)) {
      blank_counter++;
    } else if ((c == ' ') && (blank_counter > 0)) {
      c = '\0';
    } else if ((c != ' ') && (blank_counter > 0)) {
      blank_counter = 0;
    }
    putchar(c);
  }




  return 0;
}
