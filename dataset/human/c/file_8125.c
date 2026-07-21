#include<stdio.h>
int main()
{
int a,b,c,d;
long int a1,a2;
if(scanf("%d %d %d %d",&a,&b,&c,&d)!=0);
{
a1=a*b;
a2=c*d;
if(a1>a2)
printf("%ld",a1);
else
printf("%ld",a2);
}
return 0;
}
