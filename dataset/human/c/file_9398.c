#include<stdio.h>
int main()
{
int n,d,x,i,j;
scanf("%d%d%d",&n,&d,&x);
int mem[105];
for(i=1;i<=n;i++)
scanf("%d",&mem[i]);
int sum=x+n;
for(i=1;i<=n;i++)
{
    for(j=1;;j++)
        if(j*mem[i]+1<=d)
        sum++;
        else
        break;
}
printf("%d",sum);
return 0;
}
