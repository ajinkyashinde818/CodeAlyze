#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);  
	int n;
	cin >> n;
	vector<long long> sum(n + 1);
	for(int i = 1; i <= n; i++) {
		long long a;
		cin >> a;
		sum[i] = sum[i - 1] + a;
	}
	long long ans = 1e18;
	for(int i = 1; i < n; i++) {
		ans = min(ans, abs(sum[i] - (sum[n] - sum[i])));
	}
	cout << ans << endl;
	return 0;	
}
