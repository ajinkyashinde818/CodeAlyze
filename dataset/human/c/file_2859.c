#include<stdio.h>
int main()
{
    long long int k,s,x,y,z,i,j,p,count=0;
    scanf("%lld%lld",&k,&s);
    for(i=0; i<=k; i++)
    {
        x=i;
        for(j=0;j<=k;j++)
        {
            y=j;
            z=s-x-y;
                if(x+y+z==s&&z>=0&&z<=k)
                {
                   count++;
                }

        }
    }
    printf("%lld\n",count);
    return 0;
}
