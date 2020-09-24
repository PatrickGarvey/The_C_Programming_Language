#include <stdio.h>
#define MAXLINE 1000


void my_squeeze(char s1[], char s2[]);
void original_squeeze(char s[], int c);

/* Write an alternate version of squeeze(s1, s2) that delets each character
  in s1 that matches any character in the string s2. */
int main(){

  char s1[MAXLINE] = "abcdefgh";
  char s2[MAXLINE] = "cf";

  my_squeeze(s1, s2);

  printf("%s\n", s1);

  return 0;
}

void my_squeeze(char s1[], char s2[])
{
  int counter;

  counter = 0;

  while (s2[counter] != '\0'){
    printf("Removing: %c\n", s2[counter]);
    original_squeeze(s1, s2[counter]);
    counter++;
  }
}

/* squeeze: delete all c from s */
void original_squeeze(char s[], int c)
{
  int i, j;

  for(i=j=0; s[i] != '\0'; i++)
    if(s[i] != c)
      s[j++] = s[i];
    s[j] = '\0';
}
