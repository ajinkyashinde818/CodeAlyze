#include"bits/stdc++.h"

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll N;
	cin >> N;
	vector<ll>A(N);
	ll cnt = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		if (A[i] < 0) {
			cnt++;
		}
	}

	vector<ll>B(N);
	ll ans = 0;
	ll mn = 1000000000;

	if (cnt % 2 == 1) {
		for (int i = 0; i < N; i++) {
			ll tmp = abs(A[i]);
			mn = min(mn, tmp);
		}
	}
	else {
		mn = 0;
	}

	for (int i = 0; i < N; i++)
	{
		ans += abs(A[i]);
	}

	cout << ans - (mn * 2)<< endl;

	return 0;
}
