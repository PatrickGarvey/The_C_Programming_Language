#include <stdio.h>


unsigned getbits(unsigned x,int p,int n);

int main(){

  // https://stackoverflow.com/questions/197614/need-help-understanding-getbits-method-in-chapter-2-of-kr-c
  //75 in binary is 0100 1011
  long test = 75;
  printf("%ld\n", getbits(test, 4, 3));

  return 0;
}



unsigned getbits(unsigned x,int p,int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}
