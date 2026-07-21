#include<stdio.h>
#include<stdlib.h>
int fun(int ,int );
int fun(int s,int k)
{
    int i,j,t,ans=0;
    for(i=0;i<=k;i++)
    {
        for(j=0;j<=k;j++)
        {
            t=s-i-j;
            if(t>=0&&t<=k)
            {
                ans++;
            }
        }
    }
    return ans;
}
int main()
{
    int s,k;
    scanf("%d%d",&k,&s);
    printf("%d\n",fun(s,k));
    return 0;
}
