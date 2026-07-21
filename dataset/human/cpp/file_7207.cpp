#include<algorithm>
#include<math.h>
#include<cstdio>
#include<ctype.h>
#include<stdio.h>
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	ll N;
	cin >> N;
	vector<ll>v(N);
	ll sum = 0;
	ll cnt = 0;
	ll ans = 1000000000000000;
	for (ll i = 0; i < N; ++i)
	{
		cin >> v[i];
		sum += v[i];
	}
	for (ll i = 0; i < N; ++i) {
		cnt += v[i];
		if (i + 1 < N)
			ans = min(ans, abs(sum - cnt * 2));


	}
	cout << ans << endl;
}
