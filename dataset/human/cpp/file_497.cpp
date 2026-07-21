#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, a, b, c, res = 0;
	cin >> a >> b >> c >> n;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
		{
			int tmp = a * i + b * j;
			tmp = n - tmp;
			if (tmp >= 0 && tmp % c == 0) res++;
		}
	cout << res << endl;
}
