#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MaxN = 1e5;

int n;
LL a[2 * MaxN + 5];
LL sum[2 * MaxN + 5];
LL all;
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		all = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
			all += a[i];
		}
		LL ans = 1LL << 60;
		for(int i = 1; i <= n; i++)
			sum[i] = sum[i - 1] + a[i];
		if(n == 2) ans = abs(a[1] - a[n]);
		else if(n > 2) {
			for(int i = 2; i <= n - 1; i++)
				ans = min(ans, abs((all - sum[i]) - sum[i]));
		}
		printf("%lld\n", ans);
		memset(a, 0, sizeof(a));
		memset(sum, 0, sizeof(sum));
	}
	return 0;
}
