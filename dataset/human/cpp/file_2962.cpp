#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll arr[100005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		if (arr[i] < 0) {
			++cnt;
			arr[i] = -arr[i];
		}
	}
	cnt %= 2;
	sort(arr, arr + n);
	if (cnt)
		arr[0] = -arr[0];
	ll ans = 0;
	for (int i = 0; i < n; ++i)
		ans += arr[i];
	cout << ans << '\n';
	return 0;
}
