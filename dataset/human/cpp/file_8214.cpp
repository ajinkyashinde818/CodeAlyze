#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <iomanip>
#include <unordered_map>

using namespace std;
typedef long long  ll;

ll dx[] = { 1, 0 };
ll dy[] = { 0, 1 };

int main()
{
	ll N;
	cin >> N;
	vector<ll> a(N);
	vector<ll> b(N);
	for (ll i = 0; i < N; i++)
	{
		cin >> a[i];
		if (i != 0)
		{
			b[i] = b[i - 1] + a[i];
		}
		else
			b[i] = a[i];
	}
	ll ans = abs(2 * b[0] - b[N - 1]);
	for (ll i = 0; i < N - 1; i++)
	{
		ans = min(ans, abs(2 * b[i] - b[N - 1]));
	}
	cout << ans << endl;

	return 0;
}
