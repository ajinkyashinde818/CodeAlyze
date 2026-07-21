#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

long long  a[N], b[N], c[N];



int main() {

	long long n, minval = 9999999999999;

	cin >> n;

	for (int i = 0; i < n; ++i) cin >> a[i];

	for (int i = 1; i <= n; ++i) b[i] = b[i - 1] + a[i - 1];

	for (int i = n; i >= 0; --i) c[i] = c[i + 1] + a[i];

	for (int i = 1; i < n; ++i) {

		//cout<<c[i]<<" "<<b[i]<<"\n";

		minval = min(minval, abs(c[i] - b[i]));


	}

	cout << minval << '\n';






}
