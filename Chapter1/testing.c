#include <stdio.h>

int main()
{
  int result = getchar() != EOF;
  printf("%d %d\n", result, EOF);
  return 0;
}
