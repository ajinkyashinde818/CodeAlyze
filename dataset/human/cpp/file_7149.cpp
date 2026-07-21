#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	long long a[200005];
	for (int i=1;i<=n;i++) cin >> a[i];
	long long sum=0;
	for (int i=1;i<=n;i++) {
		sum+=a[i];
	}
	a[0]=0;
	for (int i=1;i<=n;i++) {
		a[i]+=a[i-1];
	}
	long long ans=2000000007;
	for (int i=1;i<n;i++) {
		ans=min(ans,abs(a[i]-(sum-a[i])));
	}
	cout << ans << endl;
	return 0;
}
