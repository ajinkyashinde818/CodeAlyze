#include<stdio.h>
int main()
{
    int n,m,i,j=0,h[200001]={0};
    scanf("%d %d",&n,&m);
    int a[m],b[m],d[m];
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&a[i],&b[i]);
        if(a[i]==1)
        {
            h[b[i]]=1;
        }
       if(b[i]==n)
       {
           d[j]=a[i];
           j++;
       }
    }
    for(i=0;i<j;i++)
    {
        if(h[d[i]])
        {
            printf("POSSIBLE\n");
            return 0;
        }
    }
    printf("IMPOSSIBLE\n");
 return 0;
}
