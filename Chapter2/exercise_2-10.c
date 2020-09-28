#include <stdio.h>
#include <ctype.h>

void my_lower(char s[]);

/* Rewrite the function lower, which converts upper case letters to lower case,
    with a conditional expression instead of if-else */
int main(){

  char test[100] = "testTEST123Test";

  printf("%s\n", test);
  my_lower(test);
  printf("%s\n", test);


  return 0;
}

/* convert uppercase into lowercase */
void my_lower(char s[]){
  for(int c = 0;s[c]!='\0';c++){
    isupper(s[c])?s[c]+=32: 1;
  }
}
