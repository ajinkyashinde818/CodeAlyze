#include<stdio.h>
int main(){
int a[10000],i,N=0;
scanf("%d",&a[0]);
for(i=1;a[i-1]!=0;i++)
{
scanf("%d",&a[i]);
N++;
}
for(i=0;i<=N-1;i++)
{printf("Case %d: %d\n",i+1,a[i]);
}
return 0;
}
