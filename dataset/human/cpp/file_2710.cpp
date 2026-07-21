#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;
inline LL max(LL a, LL b) { return  a > b ? a : b; }

LL flippingSign(int N, vector<int>& A) {
	vector<vector<LL>> dp(2, vector<LL>(N));
	
	dp[0][0] = A[0];
	dp[1][0] = -A[0];
	
	for(int i = 1; i < N-1; i++) {
		dp[0][i] = max( dp[0][i-1] + A[i], dp[1][i-1] - A[i]);
		dp[1][i] = max( dp[0][i-1] - A[i], dp[1][i-1] + A[i]);
	}
	return max(dp[0][N-2] + A[N-1], dp[1][N-2] - A[N-1]);
}

int main() {
	ios::sync_with_stdio(false);
	int N;
	
	cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	
	cout << flippingSign(N, A);
}
