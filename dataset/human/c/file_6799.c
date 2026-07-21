#include <stdio.h>
#include <stdlib.h>

int intsort(const void *a, const void *b);

int main(void)
{
  char arr[10];
  int n;
  int a[850000];
  unsigned long long int  ans=0;

  fgets(arr, sizeof(arr), stdin);
  sscanf(arr, "%d", &n);

  for (int i=0; i < n*3; ++i) {
    scanf("%d", &a[i]);
  }
  qsort(a, n*3, sizeof(int), intsort);

  for (int i=1,j=0; j < n; i += 2, j++) {
     ans += a[i]; 
  }
  printf("%lld\n", ans);
  return 0;
}

int intsort(const void *a, const void *b)
{
  if (*(int*)a > *(int*)b){
    return -1;
  }else if (*(int*)a < *(int*)b) {
    return 1;
  } else {
    return 0;
  }
}
