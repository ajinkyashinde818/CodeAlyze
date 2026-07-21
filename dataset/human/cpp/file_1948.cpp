#include <iostream>

using namespace std;

long long n, cnt, a, ans;

int main()
{
	cin>> n;
	a = 1e15;
	for (int i = 1; i <= n; i++)
	{
		long long x;
		cin >> x;
		if (x < 0)
		{
			cnt++;
			ans -= x;
			a = min(a, -x);
		}
		else
		{
			ans += x;
			a = min(a, x);
		}
	}
	if (cnt % 2 == 1)
	{
		cout << ans - a * 2 << endl;
	}
	else
	{
		cout << ans << endl;
	}
	return 0;
}
