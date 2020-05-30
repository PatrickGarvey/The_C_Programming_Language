#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */
#define MAXINPUT 10 /* maximum lines greater than 80 */

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

/* exercise 1-16 https://clc-wiki.net/wiki/K%26R2_solutions:Chapter_1:Exercise_16 */

/* Write a program to print all input lines that are longe than 80 characters */
int main()
{
  int counter;
  int len;
  char line[MAXLINE];
  char lines[MAXINPUT][MAXLINE];


  counter = 0;
  while ((len = mygetline(line, MAXLINE)) > 0) {
    if (len > 10) {
      if (counter < MAXINPUT) {
        copy(lines[counter], line);
        ++counter;
      } else {
        printf("Max Input Reached");
      }
    }
  }

  for (int i = 0; i < counter; ++i){
    printf("%s", lines[i]);
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
