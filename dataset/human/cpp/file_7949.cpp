#include <bits/stdc++.h>
using namespace std;
int main() {
	long int n; cin >> n;
	long long int a;
	long long int x[200005];
	long long int s = 0;
	for(long int i=0;i<n;i++){
		cin >> a;
		s += a;
		x[i] = s;
	}
	//long long int ans = 1000000000000000005;
	long long int ans = LLONG_MAX;
	for(long int i=0;i<n-1;i++){
		ans = min(abs(2*x[i]-s), ans);
	}
	cout << ans << endl;
	return 0;
}
