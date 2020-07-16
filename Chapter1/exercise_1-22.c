#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */
#define FOLD_POSITION 10 /* where to fold */



int mygetline(char line[], int maxline);
void slice(char substring[], char string[], int substring_start, int substring_end);


/*  Write a program to "fold" long input lines into two or more shorter
    lines after the last non-blank character that occurs before the n-th
    column of input. Make sure the program does something intelligent with
    very long lines, and if there are no blanks or tabs before the specified
    column.
    https://stackoverflow.com/questions/14797734/k-and-r-exercise-1-22 */
int main()
{
  int len, substring_start, substring_end;
  int temp_substring_end, another_counter;
  char line[MAXLINE];
  char substring[MAXLINE];



  while ((len = mygetline(line, MAXLINE)) > 0) {
    if (len > FOLD_POSITION) {
      another_counter = 1;
      substring_end = FOLD_POSITION;
      substring_start = 0;
      for (int counter = len; counter > -1; counter = counter-FOLD_POSITION) {
        if (line[FOLD_POSITION] == '\t' || line[FOLD_POSITION] == ' ') {
          printf("here");
          //slice(substring, line, substring_start, substring_end);
        } else if (substring_end > len) {
          substring_start++;
          slice(substring, line, substring_start, substring_end);
        } else {
          temp_substring_end = substring_end;
          // find the whitespace character
          while ((line[substring_end] != '\t') && (line[substring_end] != ' ')) {
            //printf("here");
            substring_end--;

            // in case there is just one very long word. We split the word
            if (substring_end == 0) {
              substring_end = temp_substring_end;
              break;
            }
          }
          slice(substring, line, substring_start, substring_end);
          another_counter = another_counter + 1;
          substring_start = substring_end;
          substring_end = substring_end + FOLD_POSITION;
        }
      }
    }


    //printf("%s", line);

  }
  return 0;
}

/* getline: read a line into s, return length */
int mygetline(char s[], int lim)
{
  int c, i;

  for (i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}


void slice(char substring[], char string[], int substring_start,  int substring_end)
{
  for (int i = 0; i<substring_end; i++) {
    substring[i] = string[i+substring_start];
  }
  substring[substring_end] = '\n';
  substring[substring_end+1] = '\0';

  //printf("here ");
  //printf("%d ", substring_start);
  //printf("%d ", substring_end);
  printf("%s", substring);
}
