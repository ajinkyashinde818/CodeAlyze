#include "bits/stdc++.h"

using namespace std;

void solve(void)
{
	int n, r, g, b;
	cin >> r >> g >> b >> n;
	int ans = 0;
	for (int x = 0; x*r <= n; x++)
		for (int y = 0; y*g <= n; y++)
		{
			int z = n - x*r - y*g;
			if (z >= 0 && z % b == 0)
			{
				ans++;
			}
		}
	cout << ans << endl;
}

int main()
{
	solve();
	//cout << "yui(*-v・)yui" << endl;
	return 0;
}
