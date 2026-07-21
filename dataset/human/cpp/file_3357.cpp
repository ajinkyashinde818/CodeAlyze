#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<algorithm>
using namespace std;


int main() {
	int N;

	cin >> N;

	vector<int> A(N);

	for (int i = 0; i < N; i++)
		cin >> A[i];

	vector<vector<long>>	dp(2, vector<long>(N+1));

	dp[0][0] = 0;
	dp[1][0] = -9999999999;

	for (int i = 1; i <= N; i++) {
		dp[0][i] = max(dp[0][i - 1] + A[i-1], dp[1][i - 1] - A[i-1]);
		dp[1][i] = max(dp[0][i - 1] - A[i-1], dp[1][i - 1] + A[i-1]);
	}
	 
	cout << dp[0][N] <<	endl;


}
