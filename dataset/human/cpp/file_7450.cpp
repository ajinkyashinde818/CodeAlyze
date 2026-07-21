#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long LL;

const int maxn = 2e5;
const LL inf = 1e15;

int a[maxn+10];

int main()
{
    int n;
    LL sum, ans, res;
    while(~scanf("%d", &n)) {
        sum = res = 0;
        ans = inf;
        for(int i = 0;i < n;i++) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        for(int i = 0;i < n-1;i++) {
            res += a[i];
            sum -= a[i];
            ans = min(ans, abs(res - sum));
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
