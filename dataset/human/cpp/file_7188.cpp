#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int Max = 2e5;

long long n, a[Max + 5];
long long sum[Max + 5], tot[Max + 5], ans = 100000000000;

int main()
{
	scanf ("%lld", &n);
	sum[0] = 0;
	for (int i = 1; i <= n; i++){
		scanf ("%lld", &a[i]);
		sum[i] = sum[i - 1] + a[i];
//		printf ("%d\n", sum[i]);
	}
	tot[n + 1] = 0; 
	for (int i = n; i >= 1; i--){
		tot[i] = tot[i + 1] + a[i];
//		printf ("%d\n", tot[i]);
	}
	for (int i = 1; i <= n - 1; i++){
//		printf ("%d  %d\n", sum[i], tot[i]);
		long long w = abs(sum[i] - tot[i + 1]);
		ans = min(ans, w);
	}
	printf ("%lld\n", ans);
}
