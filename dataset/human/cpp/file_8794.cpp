#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Max = 1e6 + 5;
string lst[Max], ls[Max];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> lst[i];
	for (int j = 1; j <= m; j++) cin >> ls[j];
	int f = 0;
	for (int i = 1; i <= n - m+1; i++)
	{
		for (int j = 1; j <= n - m+1; j++)
		{
			int tf = 1;
			for (int k = 0; k <= m-1; k++)
			{
				string str;
				str = lst[i + k].substr(j-1, m);
				if (ls[k + 1] != str)
				{
					tf = 0;
					break;
				}
			}
			if (tf == 1) f = 1;
		}
	}
	if (f)cout << "Yes" << endl;
	else cout << "No" << endl;

}
