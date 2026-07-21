#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int n, a[100000];
ll dp[100000][2];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	
	for (int i = 0; i < n; i++)
		dp[i][0] = dp[i][1] = -1e18;
	dp[0][0] = a[0];

	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + a[i];
		dp[i][1] = max(dp[i - 1][0] + 2 * -a[i - 1], dp[i - 1][1] + 2 * a[i - 1]) - a[i];
	}
	printf("%lld\n", max(dp[n - 1][0], dp[n - 1][1]));
}
