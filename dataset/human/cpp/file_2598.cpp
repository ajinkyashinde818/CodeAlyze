#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int N;
	cin >> N;
	vector<ll> A(N);
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (A[i] < 0) ++cnt;
		A[i] = abs(A[i]);
	}
	sort(A.begin(), A.end());
	ll res = accumulate(A.begin(), A.end(), 0LL);
	if (cnt & 1) res -= A[0] * 2;
	cout << res << endl;
	return 0;
}
