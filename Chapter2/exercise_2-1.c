#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <float.h>



/* Write a program to determine the ranges of char, short, int, and long
  varaibles, both signed and unsigned, by printing apporopriate values from
  standard headers and by direct computation. Harder if you compute them:
  determine the ranges of the various floating-point types. */

int main() {
  char char_test;
  short short_test;
  int int_test;
  long long_test;

  unsigned char char_range;
  unsigned short short_range;
  unsigned int int_range;
  double long_range;

  char_range = pow(2, (sizeof(char_test) * 8)) -1;
  short_range = pow(2, (sizeof(short_test) * 8)) -1;
  int_range = pow(2, (sizeof(int_test) * 8)) -1;
  long_range = pow(2, (sizeof(long_test) * 8)) -1;

  printf("--- calculate integer ---\n");
  printf("The size of char is: %d and the unsigned range is 0 - %d\n",
    sizeof(char_test), char_range);
  printf("The size of short is: %d and the unsigned range is 0 - %hu\n",
    sizeof(short_test), short_range);
  printf("The size of int is: %d and the unsigned range is 0 - %ld\n",
    sizeof(int_test), int_range);
  printf("The size of long is: %d and the unsigned range is 0 - %.0lf\n",
    sizeof(long_test), long_range);

  printf("--- limits.h ---\n");
  printf("The size of char is(in bits): %d and the unsigned range is 0 - %d\n",
    CHAR_BIT, UCHAR_MAX);
  printf("unsigned short range is 0 - %hu\n", USHRT_MAX);
  printf("unsigned int range is 0 - %ld\n", UINT_MAX);
  printf("unsigned long range is 0 - %llu\n", ULONG_MAX);


  float float_test;
  double double_test;
  // IEEE 754-1985 specifies 1bit sign 8bit exponent 23bit fraction
  // range is thus: 2^-127 - 2^128
  double float_range_min = pow(2, -125);
  double float_range_max = pow(2, 128);

  printf("--- calculate float ---\n");
  printf("The size of float is: %d and the range is %lf - %lf\n",
    sizeof(float_test), float_range_min, float_range_max);

  printf("--- float.h ---\n");
  printf("float range: %d - %d\n", FLT_MIN_EXP, FLT_MAX_EXP);


  return 0;
}
