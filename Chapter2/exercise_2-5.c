#include <stdio.h>
#define MAXLINE 1000

int any(char s1[], char s2[]);

/* Write the function any(s1, s2), which returns the first location in the
  string s1 where any character from the string s2 occurs, or -1 if s1
    contains no characters from s2. */
int main(){

  char s1[MAXLINE] = "abcdefgh";
  char s2[MAXLINE] = "fcb";

  int p = any(s1, s2);

  printf("%d\n", p);

  return 0;
}


int any(char s1[], char s2[]){
  int position = MAXLINE;

  for(int i=0; s1[i] != '\0';i++){
    for(int j=0; s2[j] != '\0';j++){
      if (s1[i] == s2[j]){
        if (i<position)
          position = i;
      }
    }
  }

  return position;
}
