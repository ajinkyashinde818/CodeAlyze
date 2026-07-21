#include <bits/stdc++.h>
using namespace std;

/*
提出前に確認!
- setとmultisetを間違えない
*/

int	main(void)
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<int> b(n);
	for (int i = 0; i < n; i++) cin >> b[i];
	int index = -1;
	int max_cnt = 0;
	int cnt = 0;
	int pre = 0;
	int pre_index = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == b[i])
		{
			if (pre == a[i]) cnt++;
			else
			{
				if (cnt > max_cnt) index = pre_index, max_cnt = cnt;
				cnt = 1;
				pre = a[i];
				pre_index = i;
			}
		}
	}
	if (cnt > max_cnt) index = pre_index;
	if (index == -1)
	{
		cout << "Yes" << endl;
		for (int i = 0; i < n; i++)
		{
			cout << b[i];
			if (i != n - 1) cout << " ";
			else cout << endl;
		}
		return (0);
	}
	int counter = 0;
	for (int j = 1; j < n; j++)
	{
		if (a[index] != b[(index + j) % n])
		{
			bool flag = true;
			for (int k = 0; k < n; k++) flag &= (a[k] != b[(k + j) % n]);
			if (flag)
			{
				cout << "Yes" << endl;
				for (int k = 0; k < n; k++)
				{
					cout << b[(k + j) % n];
					if (k != n - 1) cout << " ";
					else cout << endl;
				}
				return (0);
			}
			counter++;
			if (counter > 1000) break ;
		}
	}
	cout << "No" << endl;
	return (0);
}

/*
7
1 1 3 4 4 4 5
1 1 2 4 4 4 5
*/
