#include <stdio.h>

int main()
{
  int i,n;
  int a[20], b[20], c[20];
  int pts=0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  for (i = 0; i < n; i++) scanf("%d", &b[i]);
  for (i = 0; i < n-1; i++) scanf("%d", &c[i]);
  pts=b[a[0]-1];
  for (i = 1; i < n; i++){
    pts+=b[a[i]-1];
    if(a[i]-a[i-1]==1) pts+=c[a[i-1]-1];
  }
  printf("%d\n",pts);  
  return 0;
}
