#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <ctime>
#include <map>
#include <stack>
#include <sstream>
#include <set>
#include <cmath>
#include <functional>

using namespace std;

int main(void)
{
	int n, m;
	vector <string> a, b;
	string s;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		a.push_back(s);
	}
	for (int j = 0; j < m; j++)
	{
		cin >> s;
		b.push_back(s);
	}

	for (int i = 0; i < n - m + 1; i++)
	{
		for (int j = 0; j < n - m + 1; j++)
		{
			bool flag = true;
			for (int x = 0; x < m; x++)
			{
				for (int y = 0; y < m; y++)
				{
					if (b[x][y] != a[i + x][j + y])
					{
						flag = false;
						break;
					}
				}
				if (flag == false)
				{
					break;
				}
			}
			if (flag == true)
			{
				cout << "Yes" << endl;
				return 0;
			}
		}
	}

	cout << "No" << endl;
	return 0;
}
