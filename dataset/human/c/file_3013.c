#include<stdio.h>

int main()
{
    long long int n,k,i;
    scanf("%lld %lld",&k,&n);
    long long int house[n];
    for(i=0;i<n;i++)
    {
        scanf("%lld",&house[i]);
    }
long long int max = 0;
    for(i=1;i<n;i++)
    {
        if((house[i]-house[i-1])>max)
        {
            max = house[i]-house[i-1];
        }
    }

    if(k+ house[0]-house[n-1]>max)
    {
        max = k + house[0] - house[n-1];
    }

    printf("%lld",k-max);
}
