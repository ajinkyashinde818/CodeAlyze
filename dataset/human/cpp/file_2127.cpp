#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int n, i, a[100000], m=1000000000, k=0;
    long long sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<0)
        {
            a[i]=-a[i];
            k++;
        }
        sum=sum+a[i];
        if(a[i]<m)
            m=a[i];

    }
    if(k%2==1)
    {
        sum=sum-2*m;
    }
    printf("%lld",sum);
    return 0;
}
