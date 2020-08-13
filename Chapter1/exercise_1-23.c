#include <stdio.h>
#include <stdbool.h>


/* Write a program to remove all comments from a C program. don't forget to
handle quoted stings and character constants properly. C comments do not nest */

int main()
{
  bool in_comment = false;
  bool in_char = false;
  bool single_line_comment = false;
  bool multi_line_comment = false;
  bool first_check = false;

  FILE *f = fopen("test_file.txt", "r");
  int c = getc(f);

  while (c != EOF) {
    // check char and string
    if ((c == '\'') || (c == '\"')){
      if (in_char) {
        in_char = false;
      } else {
        in_char = true;
      }
      putchar(c);
    // ignore comment
    } else if (single_line_comment) {
      if (c == '\n') {
        single_line_comment = false;
      } else {
        ;
      }
    // ignore multi line comment
    } else if (multi_line_comment) {
      if (c == '*') {
        first_check = true;
      } else if ((c == '/') && (first_check)){
        multi_line_comment = false;
        first_check = false;
      } else {
        ;
      }
    // check which comment
    } else if ((c == '/') && !(in_char) && !(single_line_comment)){
        if (!in_comment){
          in_comment = true;
        } else {
          if (c == '/') {
            single_line_comment = true;
          }
          in_comment = false;
        }
    } else if ((c == '*') && (in_comment) && !(in_char)) {
      multi_line_comment = true;
    } else {
      putchar(c);
    }

    c = getc(f);
  }
  fclose(f);

  return 0;
}
