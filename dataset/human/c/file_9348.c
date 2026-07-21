#include<stdio.h>
int main()
{
    int n,d,x,a[200];
    int i,j,sum=0,k;
    scanf("%d",&n);
    scanf("%d %d",&d,&x);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;;j++)
        {
            k=a[i]*j+1;
            if(k<=d)
                sum++;
            else
                break;

        }
    }
    sum=sum+x;
    printf("%d\n",sum);
    return 0;
}
