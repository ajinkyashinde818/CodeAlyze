#include <stdio.h>
#include <stdlib.h>

int cmpnum(const void * n1, const void * n2)
{
	if (*(long *)n1 > *(long *)n2)
	{
		return -1;
	}
	else if (*(long *)n1 < *(long *)n2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main(void){

  long n;
  scanf("%ld", &n);
  long a[n*3];
  for (long i = 0; i < n*3; i++) {
    scanf("%ld", &a[i]);
  }
  qsort(a, n*3, sizeof(long), cmpnum);
  long sum = 0;
  for (long i = 1; i < n*2; i += 2) {
    sum += a[i];
  }
  printf("%ld\n", sum);

  return 0;
}
