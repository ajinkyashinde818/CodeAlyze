#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
long long a[200005],b[200005],c[200005];
int main()
{
    int n;
    long long sum = 0,sum1 = 0;
    long long ans = 1000000000000000;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%lld",&a[i]);
        sum1 += a[i];
    }
    for(int i = 1; i < n; i++){
        sum += a[i];
        b[i] = sum;
        c[i] = sum1 - b[i];
    }
    for(int i = 1; i < n;  i++){
        ans = min(ans,abs(b[i] - c[i]));
    }
    printf("%lld\n",ans);
    return 0;
}
