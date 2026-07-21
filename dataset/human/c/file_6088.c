#include<stdio.h>
#include<limits.h>
int min(int a,int b)
{
    return (a>b)?b:a;
}
int max(int a,int b)
{
    return (a>b)?a:b;
}
int main()
{
    int R[200000],n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&R[i]);

    int minv=R[0];
    int maxv=INT_MIN;

    for(int i=1;i<n;i++)
    {
        maxv=max(maxv,R[i]-minv);
        minv=min(R[i],minv);
    }
    printf("%d\n",maxv);
}
