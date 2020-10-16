#include <stdio.h>
#include <time.h>
#include <math.h>

#define N 10

int my_binsearch(int x, int v[], int n);
int binsearch(int x, int v[], int n);

/* Our binary search makes two test inside the loop, when one would suffice
    (at the price of more tests outside). Write a version with only one test
    inside the loop and measure the difference in run-time. */
int main(){

  clock_t start, end;
  double cpu_time_used;


  int test[N] = {1,2,7,8,13,15,19,27,53,99};
  int result;

  // binsearch with benchmark
  start = clock();
  result = binsearch(7, test, N);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("result: %d, time:%lf\n", result, cpu_time_used);

  // my implementation of binsearch with benchmark
  start = clock();
  result = my_binsearch(7, test, N);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("result: %d, time:%lf\n", result, cpu_time_used);

  return 0;
}

/* shorter implementation of binsearch */
// but takes longer now ...mh
// solution differs only sligthly
int my_binsearch(int x, int v[], int n)
{
  int low, high, mid, max_time;

  max_time = log(n) + 1;
  low = 0;
  high = n - 1;
  for(int i = 0;i<max_time;i++) {
    mid = (low+high) / 2;
    if (x < v[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }
  if (v[mid] == x){
    return mid;
  } else {
    return -1;
  }

}


/* binsearch: find x in v[0] <= v[1] <= ... <= v[n=1] */
int binsearch(int x, int v[], int n)
{
  int low, high, mid;

  low = 0;
  high = n - 1;
  while(low <= high) {
    mid = (low+high) / 2;
    if (x < v[mid])
      high = mid - 1;
    else if (x > v[mid])
      low = mid + 1;
    else
      return mid;
  }
  return -1;
}
