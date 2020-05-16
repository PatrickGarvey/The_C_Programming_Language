#include <stdio.h>

int main()
{
  float fahr, celsius;
  int lower, upper, step;
  char heading[];

  lower = 0;      /* lower limit of temperature table */
  upper = 300;    /* upper limit */
  step = 20;      /* step size */
  heading = "Fahrenheit-Celsius_table";

  printf("%s\n", heading);
  fahr = lower;
  while (fahr <= upper) {
    celsius = (5.0/9.0) * (fahr-32.0);
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
  return 0;
}
