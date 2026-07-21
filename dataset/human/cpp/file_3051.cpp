#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<long long> A(N);
	for(auto &i:A)cin >> i;
	
	long long dp[N-1][2];
	for(int i=0;i<N-1;i++)for(int j=0;j<2;j++)dp[i][j]=-9999999999999999ll;
	dp[0][0]=A[0]+A[1];
	dp[0][1]=0-(A[0]+A[1]);
	
	for(int i=1;i<N-1;i++){
		dp[i][0]=max(dp[i-1][0],dp[i-1][1])+A[i+1];
		dp[i][1]=max(dp[i-1][0]-2*A[i],dp[i-1][1]+2*A[i])-A[i+1];
	}
	cout << max(dp[N-2][0],dp[N-2][1]) << endl;
	return 0;
}
