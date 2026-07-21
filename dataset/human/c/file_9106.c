#include<stdio.h>
#include<stdlib.h>
int main()
{
 int x,y,i,a[100000],fact=0;
 scanf("%d %d ",&x,&y);
for(i=1;i<=x;i++)
{
  scanf("%d",&a[i]);
}
for(i=1;i<=x;i++)
{
    if(a[i]>=y)
    {
        fact++;
    }
}
    printf("%d",fact);
}
