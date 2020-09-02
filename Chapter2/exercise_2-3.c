#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAXLINE 1000

int htoi(char hex[]);

/* (12)₁₆ = (1 × 16¹) + (2 × 16⁰) = (18)₁₀
    (1C)₁₆ = (1 × 16¹) + (12 × 16⁰) = (28)₁₀
    AB12 = 2578 */
int main(){

  char test[MAXLINE] = "12";
  char test2[MAXLINE] = "0x12";
  char test3[MAXLINE] = "0X12";
  char test4[MAXLINE] = "1C";
  char test5[MAXLINE] = "A12";

  printf("%d\n", htoi(test));
  printf("%d\n", htoi(test2));
  printf("%d\n", htoi(test3));
  printf("%d\n", htoi(test4));
  printf("%d\n", htoi(test5));

  return 0;
}

// convert string hex into integer
// todo? does not check for invalid input
int htoi(char hex[]){
  int result = 0;
  int exponent = 0;


  for(int i = strlen(hex)-1; i>=0; i--){
    // check 0x and 0X, if found stop
    if ((hex[i] == 'x') || (hex[i] == 'X')){
      break;
    } else if (isdigit(hex[i])) {
      result += (hex[i] - '0') * pow(16, exponent);
    } else {
      switch(tolower(hex[i]))
      {
        case 'a':
          result += 10 * pow(16, exponent);
          break;
        case 'b':
          result += 11 * pow(16, exponent);
          break;
        case 'c':
          result += 12 * pow(16, exponent);
          break;
        case 'd':
          result += 13 * pow(16, exponent);
          break;
        case 'e':
          result += 14 * pow(16, exponent);
          break;
        case 'f':
          result += 15 * pow(16, exponent);
          break;
      }
    }
    exponent++;
  }

  return result;
}
