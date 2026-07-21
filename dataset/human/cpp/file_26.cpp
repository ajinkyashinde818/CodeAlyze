#include<iostream>

using namespace std;

int main()
{
	int r, g, b, n, ans = 0;
	cin >> r >> g >> b >> n;

	for (int i = 0; i <= n; i += r)
	{
		for (int j = 0; j <= n - i; j += g)
		{
			if (i + j == n)
			{
				++ans;
				break;
			}
			else if ((n - i - j) % b == 0)
			{
				++ans;
			}
		}
	}

	cout << ans;

	return 0;
}
