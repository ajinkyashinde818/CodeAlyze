#include <bits/stdc++.h>
using namespace std;

int main()
{
	int64_t r, g, b, n;

	cin >> r >> g >> b >> n;

	int64_t ans = 0;

	for (int64_t i = 0; i * r <= n; i++)
	{
		for (int64_t j = 0; i * r + j * g <= n; j++)
		{
			if ((n - i * r - j * g) % b != 0)
			{
				continue;
			}
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}
