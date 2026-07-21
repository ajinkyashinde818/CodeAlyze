#include<stdio.h>
#include<string.h>
int N,M;
int a[200005],b[200005];
int main()
{
    while(~scanf("%d%d",&N,&M))
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=0;i<M;i++)
        {
            int c,d;
            scanf("%d%d",&c,&d);
            if(c==1)
                a[d]=1;
            if(d==1)
                a[c]=1;
            if(c==N)
                b[d]=1;
            if(d==N)
                b[c]=1;
        }
        int flag = 0;
        for(int i=1;i<=N;i++)
        {
            if(b[i]==1&&a[i]==1)
            {
                flag = 1;
                break;
            }
        }
        if(flag)
            printf("POSSIBLE\n");
        else
            printf("IMPOSSIBLE\n");
    }



    return 0;
}
