#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long a[200005];
int main()
{
    long long n, sum=0, x=0, res;
    scanf("%lld", &n);
    for(int i=0; i<n; i++){
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    res = abs(a[0]-(sum-a[0]));
    for(int i=0; i<n-1; i++){
        x += a[i];
        res = min(res, abs(x - (sum - x)));
    }
    printf("%lld\n", res);
    return 0;
}
