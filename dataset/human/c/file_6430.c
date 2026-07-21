#include <stdio.h>

int main()
{
  int n,mnv,mxv,i;
  int a[200000];
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }

  mnv = a[0];
  mxv = a[1]-a[0];
  for(i=1;i<n;i++)
  {
    if((a[i]-mnv)>mxv)mxv=(a[i]-mnv);
    if(mnv>a[i])mnv=a[i];
  }

  printf("%d\n",mxv);
  return 0;
}
