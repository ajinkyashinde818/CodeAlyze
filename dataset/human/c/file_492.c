#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n;
  int *a;

  scanf("%d", &n);
  a = (int *)malloc(sizeof(int) * n);
  if(a == NULL) {
    printf("malloc() failed.\n");
    return 1;
  }

  int i;
  for(i=0;i<n;i++) {
    scanf("%d", &a[i]);
  }

  long int s_sunuke = a[0], s_racoon = 0;
  for(i=1;i<n;i++) {
    s_racoon += a[i];
  }
  long int diff = s_sunuke - s_racoon;
  long int diff_min = labs(diff);
  for(i=1;i<n-1;i++) {
    diff += 2 * a[i];
    long int temp = labs(diff);
    if(diff_min > temp) diff_min = temp;
  }
  printf("%ld", diff_min);
  free(a);
  return 0;
}
