#include <stdio.h>
 
int main(void) {
  int k,n,i,j,max;
  int a[200000];
  scanf("%d %d", &k, &n);
  for (i=0; i<n; i++) {
  	scanf("%d", &a[i]);
  }
  max = a[0]+k-a[n-1];
  for (i=0; i<n-1; i++) {
    j = a[i+1]-a[i];
    if (j>max) {
      max = j;
    }
  }
  printf("%d", k-max);
  return 0;
}
