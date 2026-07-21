#include<stdio.h>
#include<string.h>
int a[200010],b[200010];
int main()
{
    int n,m,i,j,k;
    while(~scanf("%d%d",&n,&m))
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
         int k,p=0;
       for(i=0;i<m;i++)
            {
            scanf("%d%d",&k,&j);
            if(k==1) a[j]=1;
            if(j==n) b[k]=1;
            if(k==1&&j==n) p=1;
            }
        if(p==1) {printf("POSSIBLE\n");continue;}
       for(i=1;i<n;i++)
           if(a[i]==1&&b[i]==1)   {printf("POSSIBLE\n");break;}
        if(i>=n) printf("IMPOSSIBLE\n");
    }
}
