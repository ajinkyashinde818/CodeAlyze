#include<stdio.h>
int main()
{
    int n,i,j,d,x,s=0,sum;
    scanf("%d",&n);
    int a[n];
    scanf("%d %d",&d,&x);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=1;j<=d;j++)
        {
            sum=j*a[i]+1;
            if(sum>d)
                break;
            else
                s++;
        }
        sum=0;
    }
    printf("%d\n",s+x+n);
}
