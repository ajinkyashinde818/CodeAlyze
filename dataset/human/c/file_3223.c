#include <stdio.h>
 
int main()
{
    int k,n;
    scanf("%d %d", &k, &n);
 
   int a[n];
  for(int i=0; i<n; i++) {
    scanf("%d", &a[i]);
  }
  int max = 0;
  for(int i=0; i<n-1; i++) {
    if(a[i+1] - a[i] > max)
    max = a[i+1] - a[i];
  }
  
  if(a[0] - a[n-1] + k > max)
    max = a[0] - a[n-1] + k;
  
  printf("%d", k - max);
    return 0;
}
