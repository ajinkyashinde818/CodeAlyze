#include<stdio.h>
#include<string.h>
int main()
{
    int a,b,k;
    scanf("%d%d%d",&a,&b,&k);
    int ans=0;
    for(int i=100;i>=1;i--)
    {
        if(a%i==0&&b%i==0)
            ans++;//printf("%d %d\n",i,ans);
        if(ans==k)
        {
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}
