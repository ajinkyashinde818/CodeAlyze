#include<stdio.h>
int main()
{
    int n,m,s,b,i,j;
    int a[100];
    scanf("%d",&n);
    scanf("%d%d",&m,&b); 
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    s=0;
    for(i=0;i<n;i++)
    {
        if(a[i]<m)
        {
            for(j=1;;j++)
            {
                if(j*a[i]+1>m)
                {
                    s+=j-1;
                    break;
                }                
            }
        }
    }
    printf("%d\n",s+b+n);
    return 0;
}
