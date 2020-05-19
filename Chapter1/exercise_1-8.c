#include <stdio.h>

int main()
{
  int c, nl, nb, nt;

  nl = 0;
  nb = 0;
  nt = 0;

  while ((c = getchar()) != EOF)  // Ctrl + D to invoke EOF
    if (c == '\n')
      ++nl;
    else if (c == '\t')
      ++nt;
    else if (c == ' ')
      ++nb;

  printf("newline: %d\ntabs: %d\nblanks: %d\n", nl, nt, nb);
  return 0;
}
