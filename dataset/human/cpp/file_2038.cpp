#include <bits/stdc++.h>
/// TONI BO$$ was here
/// #MLC

using namespace std;

int main()
{
    long long n,minabs,nrminus,sum,x;
    scanf("%lld",&n);
    minabs=LLONG_MAX;
    nrminus=0;
    sum=0;
    while(n--)
    {
        scanf("%lld",&x);
        if(x<0)
            nrminus++;
        minabs=min(minabs,abs(x));
        sum+=abs(x);
    }
    printf("%lld",sum-2*(nrminus%2)*minabs);

    return 0;
}
