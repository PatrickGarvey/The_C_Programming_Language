#include <stdio.h>
#define MAXLINE 1000  /* maximum input line size */

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);
void reverse_copy(char to[], char from[], int len);

/* print longest input line */
int main()
{
  int len;
  char line[MAXLINE];
  char reverse[MAXLINE];

  while ((len = mygetline(line, MAXLINE)) > 0)

    reverse_copy(reverse, line, len);
    //printf("%s", reverse);

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

/* reverse_copy: 'from' into 'to' backwards */
void reverse_copy(char to[], char from[], int len)
{
  int i;
  int j;

  i = len-2;
  j = 0;
  while (i > -1) {
    to[j] = from[i];
    --i;
    ++j;
  }
  to[len-1] = '\n';
  printf("%s", to);

}
