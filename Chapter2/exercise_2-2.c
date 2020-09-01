#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int mygetline(char line[], int maxline);
int anothergetline(char line[], int maxline);


/* Write a loop equivalent to the for loop above without using && or ||.
   the loop is in mygetline */
int main(){


  int len;
  char line[MAXLINE];



  while ((len = anothergetline(line, MAXLINE)) > 0) {
    printf("%s", line);
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

/* getline: read a line into s, return length */
int anothergetline(char s[], int lim)
{
  int c, i;

  for (i=0; i<lim-1; ++i) {
    if ((c=getchar()) != EOF){
      if (c!='\n'){
        s[i] = c;
      } else {
        break;
      }
    } else {
      break;
    }
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}
