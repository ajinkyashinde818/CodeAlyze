#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<string> a(n), b(m);
	for (auto&& ai : a) cin >> ai;
	for (auto&& bi : b) cin >> bi;
	bool found = false;
	for (int r = 0; r < n-m+1; r++)
	{
		for (int c = 0; c < n-m+1; c++)
		{
			found = true;
			for (int i = 0; i < m; i++)
				if (a[i+r].substr(c, m) != b[i])
				{
					found = false;
					break;
				}
			if (found) break;
		}
		if (found) break;
	}
	cout << (found ? "Yes" : "No") << endl;
	return 0;
}
