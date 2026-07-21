#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long int A[100005];

long long int dp[100005][2];

int main(void) {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	for (int i = 1; i <= N; i++) {
		dp[i][0] = -9999999999999999;
		dp[i][1]= -9999999999999999;
	}

	dp[2][0] = A[1] + A[2];
	dp[2][1] = -A[1] - A[2];

	for (int i = 3; i <= N; i++) {
		dp[i][0] = max(dp[i][0], dp[i - 1][0] + A[i]);
		dp[i][1] = max(dp[i][1], dp[i - 1][0] - A[i - 1] * 2 - A[i]);
		dp[i][0] = max(dp[i][0], dp[i - 1][1] + A[i]);
		dp[i][1] = max(dp[i][1], dp[i - 1][1] + A[i - 1] * 2 - A[i]);
	}

	cout << max(dp[N][0], dp[N][1]) << endl;


	//system("pause");
	return 0;
}
