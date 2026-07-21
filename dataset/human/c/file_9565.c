#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,d,x,s;

    while(scanf("%d%d%d",&n,&d,&x)!=EOF)
    {
        int a[105];
        int k,j,i,sum=0;
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(j=0; j<n; j++)
        {
            s=a[j];
            for(k=1; k<=d;)
            {
                sum++;
                k=k+s;
            }
        }
        printf("%d\n",sum+x);
    }
    return 0;
}
