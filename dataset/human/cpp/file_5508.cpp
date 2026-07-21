#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, R;
	cin >> N >> R;
	int ans;

	if (N >= 10)
	{
		ans = R;
	} else {
		ans = R+100*(10-N);
	}
	cout << ans << "\n";
}
