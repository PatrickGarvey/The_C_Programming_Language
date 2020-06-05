#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */
#define TABSIZE 8    /* tabstop every 8 characters. The ninth char is a new tab. */


int mygetline(char line[], int maxline);
void copy(char to[], char from[]);


/*  Write a program detab that replaces tabs in the input with the proper
    number of blanks to space to the next tab stop.*/
int main()
{
  int len;
  char line[MAXLINE];
  int current_tab_len;

  while ((len = mygetline(line, MAXLINE)) > 0) {
    current_tab_len = 0;
    for (int i = 0; i<len; ++i) {
      if (line[i] == '\t') {
        current_tab_len = TABSIZE - (i % TABSIZE);

        for(int j = 0; j<current_tab_len; ++j) {
          putchar(' ');
        }

      } else {
        putchar(line[i]);
      }
    }
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
