#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
  int n,k,sa;
  int max=0;
  scanf("%d%d",&k,&n);
  int a[n];
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(int i=0;i<n-1;i++){
    sa=a[i+1]-a[i];
    if(max<sa) max=sa;
  }
  sa=k-a[n-1]+a[0];
  if(max<sa) max=sa;
  printf("%d",k-max);
  return 0;
}
