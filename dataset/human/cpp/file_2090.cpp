#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;

int vis[MAXN][2], N;
ll dp[MAXN][2], arr[MAXN];

ll solve(int a, int sign){
	if(a == N) return (sign == 0) ? arr[a] : -arr[a];
	if(vis[a][sign]) return dp[a][sign];
	vis[a][sign] = 1;
	if(sign == 0) return dp[a][sign] = max(arr[a] + solve(a+1,0), -arr[a] + solve(a+1, 1));
	else return dp[a][sign] = max(-arr[a] + solve(a+1,0), arr[a] + solve(a+1, 1));
}

int main(){

	cin >> N;
	for(int i = 1;i<=N;i++) cin >> arr[i];

	cout << solve(1, 0) << endl;

	return 0;

}
