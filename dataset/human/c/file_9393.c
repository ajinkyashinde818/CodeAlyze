#include<stdio.h>

int main()
{
    int n,d,x,k,a[200];
    scanf("%d%d%d",&k,&d,&x);
    n=k;
    while(n--)
        scanf("%d",&a[n]);
    int i,j,s=0;
    for(i=0;i<k;i++)
    {
        for(j=0;;j++)
        {
            if(a[i]*j+1<=d)
                s++;
            else
                break;
        }
    }
    printf("%d\n",s+x);
    return 0;
}
