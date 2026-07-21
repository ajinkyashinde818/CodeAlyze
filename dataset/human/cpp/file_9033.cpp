#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	string a[50], b[50];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	bool ok = false;
	for (int i = 0; i <= n - m; i++)
		for (int j = 0; j <= n - m; j++)
		{
			bool tmp = true;
			for (int k = 0; k < m; k++)
				if (a[i + k].substr(j, m) != b[k])
					tmp = false;
			if (tmp)
				ok = true;
		}
	if (ok)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
