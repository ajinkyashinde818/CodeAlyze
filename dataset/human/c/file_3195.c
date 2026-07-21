#include<stdio.h>
int a[200005],b[200005];
int main ()
{  int k,n;  scanf("%d %d",&k,&n);
   for(int i=1;i<=n;i++)
      scanf("%d",&a[i]);
    int max=a[2]-a[1];
    for(int i=2;i<=n;i++)
       {  if(max<a[i]-a[i-1])  max=a[i]-a[i-1];
	   }
	   if(max<k-a[n]+a[1])  max=k-a[n]+a[1];
	printf("%d",k-max);
}
