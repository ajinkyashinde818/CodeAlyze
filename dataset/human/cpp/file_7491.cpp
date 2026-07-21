#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 200000;
int a[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    long long p=2147483647,z,sum1=0,sum2=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum1+=a[i];
    }
    for(int j=n-1;j>0;j--)
    {
        sum1-=a[j];
        sum2+=a[j];
        z=abs(sum1-sum2);
        if(z<p)
            p=z;
    }
    printf("%d\n",p);
    return 0;
}
