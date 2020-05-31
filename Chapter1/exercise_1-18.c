#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */
#define MAXINPUT 10 /* maximum lines greater than 80 */

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);
void remove_trailing(char line[], int len);

/* Write a program to remove trailing blanks and tabs from each line of
    input, and to delete entirely blank lines */
int main()
{
  int counter;
  int len;
  char line[MAXLINE];
  char lines[MAXINPUT][MAXLINE];


  counter = 0;
  while ((len = mygetline(line, MAXLINE)) > 0) {

    if ((line[len-2] == '\t') || (line[len-2] == ' ')) {
      //printf("removing trailing");
      remove_trailing(line, len);
    }

    if (counter < MAXINPUT) {
      if (line[0] == '\n'){
        ; // skip blank lines
      } else {
        copy(lines[counter], line);
        ++counter;
      }

    } else {
      printf("Max Input Reached");
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

/* remove trailing blanks and tabs */
void remove_trailing(char line[], int len)
{
  int i;

  i = len-2;
  while ((line[i] == '\t') || (line[i] == ' ')) {
    --i;
  }
  line[i+1] = '\n';
  line[i+2] = '\0';

}
