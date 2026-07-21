#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
  if (a>b) return a;
  else return b;
}
int min(int a, int b)
{
  if (a<b) return a;
  else return b;
}
 
int compare_int(const void *a, const void *b)
{
  return *(int*)b - *(int*)a;
}

int main()
{
  int k, n;
  scanf("%d %d", &k, &n);
  int a[n];
  for(int i=0;i<n;i++) scanf("%d", &a[i]);
  
  qsort(a, n, sizeof(int), compare_int);
  
  int b[n];
  for(int i=1;i<n;i++) b[i]=a[i-1]-a[i];
  
  b[0]=min(abs(a[0]-a[n-1]), abs(a[n-1]+k-a[0]));

  int max=0;
  for(int i=0;i<n;i++){
    if(b[i]>max) max = b[i];
  }
  printf("%d", k-max);
  return 0;
}
