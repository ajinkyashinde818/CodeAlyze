#include <stdio.h>
#define N 200000
int main()
{
  int n, a[N], i, max=0, min=0, j;
  scanf("%d",&n);
  for(i=0; i<n; i++) scanf("%d",&a[i]);

  min = a[0];
  max = a[1] - a[0];
  for(j=1; j<n; j++){
    if(max<(a[j]-min)) max = a[j]-min;
    if(min>a[j]) min = a[j];
  }
  printf("%d\n",max);
  return 0;
}
