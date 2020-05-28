#include <stdio.h>

#define IN 1
#define OUT 0

/*
exercse 1-11: How would I test the program?
--> different kinds of input
- works for all kinds of input(special characters, ...)
- works with no input
- what happens when we exceed int size?
- what is maximun file size?

unit test: https://clc-wiki.net/wiki/K%26R2_solutions:Chapter_1:Exercise_11
*/

/* count lines, words and characters i input */
int main()
{
  int c, nl, nw, nc, state;

  state = OUT;
  nl = nw = nc = 0;
  while ((c = getchar()) != EOF){
    ++nc;  // number of  characters
    if (c == '\n')
      ++nl;  // number of new lines
    if (c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++nw;  // number of words
    }
  }
  printf("%d %d %d\n", nl, nw, nc);
  printf("%d\n", sizeof(int));
}
