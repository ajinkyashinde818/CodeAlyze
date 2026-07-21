#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long long int sum_1(long long int *p,int i);
long long int sum_2(long long int *q,int i,int n);
int main(void)
{
 long long int x=0,y=0,min,Lmin,j;
 int i,n;
 scanf("%d",&n);
 long long int a[n],f,h;
 for(i=0;i<n;i++)
 {
  scanf("%lld",&a[i]);
  if(i<n-1) x+=a[i];
 }
  y=a[n-1];
  min=llabs(x-y);
 for(i=n-2;i>0;i--)
 {
  x-=a[i];
  y+=a[i];
  Lmin=llabs(x-y);
  if(Lmin<min) min=Lmin;
 }
   printf("%lld",min);
}
