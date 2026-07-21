#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
long long MIN;
int a[200005];
long long sum[200005];
int main()
{
	MIN = (long long)1 << 60;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), sum[i] = sum[i - 1] + a[i];
	for(int i = 1; i <= n - 1; i++)
	{
		long long t = sum[n] - sum[i];
		MIN = min(MIN, abs(t - sum[i]));
	}
	printf("%d\n", MIN);
	return 0;
}
