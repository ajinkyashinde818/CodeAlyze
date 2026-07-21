#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m;
	string k = "No";
	cin >> n >> m;
	vector<string> a(n),b(m);
	for(int i = 0;i < n;i++)
	{
		cin >> a.at(i);
	}
	for(int i = 0;i < m;i++)
	{
		cin >> b.at(i);
	}
	for(int i = 0;i < n - m + 1;i++)
	{
		for(int j = 0;j < n - m + 1;j++)
		{
			int loo = 0;
			for(int l = 0;l < m;l++)
			{
				if(b.at(l) != a.at(j + l).substr(i,m))
				{
					loo = 1;
					break;
				}
			}
			if(loo == 0)
			{
				k = "Yes";
				break;
			}
		}
		if(k == "Yes")
		{
			break;
		}
	}
    cout << k << endl;
	return 0;
}
