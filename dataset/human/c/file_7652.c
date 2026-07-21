#include <stdio.h>
#define DATA_SIZE 10000
int main(void)
{
  int i, j;
  int a[DATA_SIZE];

  for (i = 0; i < DATA_SIZE; i++) {
	scanf("%d", &a[i]);
	if (a[i] == 0)
	  break;
  }

  if (i < DATA_SIZE) {
	for (j = 0; j < i; j++) {
	  printf("Case %d: %d\n", j + 1, a[j]);
	}
  }

  else {
	for (j = 0; j < DATA_SIZE; j++) {
	  printf("Case %d: %d\n", j + 1, a[j]);
	}
  }
  return 0;
}
