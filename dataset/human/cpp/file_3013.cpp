#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	long long a[n];
	int minus_count = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < 0) {
			minus_count++;
		}
	}
	long long sumabs = 0;
	for (int i = 0; i < n; i++)
		sumabs += abs(a[i]);
	if (minus_count%2 == 0) {
		cout << sumabs << endl;
	} else {
		long long ans;
		for (int i = 0; i < n; i++) {
			if (i == 0)
				ans = sumabs - abs(a[i])*2;
			else
				ans = max(ans, sumabs - abs(a[i])*2);
		}
		cout << ans << endl;
	}
	return 0;
}
