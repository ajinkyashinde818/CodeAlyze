#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>>
using namespace std;

long long a[200005];
int main()
{
    int n;
    scanf("%d",&n);
    long long s=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        s+=a[i];
    }
    long long ss=0;
    ss+=a[1];
    s-=a[1];
    long long x=fabs(ss-s);
    for(int i=2;i<=n-1;i++)
    {
        ss+=a[i];
        s-=a[i];
        if(fabs(ss-s)<x)
                x=fabs(ss-s);
    }
        printf("%lld\n",x);
    //cout << "Hello world!" << endl;
    return 0;
}
