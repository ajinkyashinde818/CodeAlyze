#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;

int N;
ll dp[100000][2];
ll ar[100000];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)cin >> ar[i];
	dp[0][0] = ar[0], dp[0][1] = -ar[0];
	for (int i = 1; i < N; i++) {
		if (i != N - 1) {
			dp[i][0] = max(dp[i - 1][0] + ar[i], dp[i - 1][1] - ar[i]);
			dp[i][1] = max(dp[i - 1][0] - ar[i], dp[i - 1][1] + ar[i]);
		}
		else {
			dp[i][0] = dp[i - 1][0] + ar[i];
			dp[i][1] = dp[i - 1][1] - ar[i];//最後の数字の反転は一つ前に依存
		}
	}
	cout << max(dp[N - 1][0], dp[N - 1][1]) << endl;
	return 0;
}
