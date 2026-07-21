#include<stdio.h>
int main()
{
  int k,n,ma=0;
  scanf("%d",&k);
  scanf("%d",&n);
  int a[n],d[n],i;
  scanf("%d",&a[0]);
  for(i=1;i<n;i++)
  {
    scanf("%d",&a[i]);
    	d[i]=a[i]-a[i-1];
  }
  d[0]=k+a[0]-a[n-1];
  for(i=2;i<n;i++)
  {
    if(d[ma]<d[i])
      ma=i;
  }
  printf("%d\n",k-d[ma]);
  return 0;
}
