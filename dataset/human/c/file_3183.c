#include<stdio.h>
int main()
{
    int k,a,n,ai[200001],i,j,m=0,s=0,b,c,d,e,f=0;
    scanf("%d%d",&k,&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&ai[i]);
    }
    b=k-ai[n-1]+ai[0];
    for(i=0;i<n-1;i++)
    {
        c=ai[i+1]-ai[i];
        if(m<c)
        {
            m=c;
        }
    }
    if(b>=m)
    {
        for(i=0;i<n-1;i++)
        {
            a=ai[i+1]-ai[i];
            s=s+a;
        }
        printf("%d\n",s);
    }
    else
    {
        for(i=0;i<n-1;i++)
        {
            a=ai[i+1]-ai[i];
            if(a==m && !f)
                { f=1;
                    continue;}
            s=s+a;
        }
        s=s+(k-ai[n-1]);
        s=s+ai[0];
        printf("%d\n",s);
    }
    return 0;

}
