#include <stdio.h>
#include <stdlib.h>

int cmpnum(const void * n1, const void * n2) {
	if (*(long *)n1 > *(long *)n2)
	{
		return 1;
	}
	else if (*(long *)n1 < *(long *)n2)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int main(void) {

  long n;
  scanf("%ld", &n);
  long a[n];
  for (long i = 0; i < n; i++) {
    scanf("%ld", &a[i]);
  }
  long zero = 0;
  long minus = 0;
  long sum = 0;
  for (long i = 0; i < n; i++) {
    if (a[i] == 0) {
      zero++;
    }
    if (a[i] < 0) {
      minus++;
      a[i] *= -1;
    }
    sum += a[i];
  }
  if (zero != 0 || minus%2 == 0) {
    printf("%ld\n", sum);
    return 0;
  }
  qsort(a, n, sizeof(long), cmpnum);
  sum -= a[0]*2;
  printf("%ld\n", sum);

  return 0;
}
