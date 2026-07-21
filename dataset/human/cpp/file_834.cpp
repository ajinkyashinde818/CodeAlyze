#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> Q;

int n, r, g, b, ans;
string s[10010];

int main()
{
	cin >> r >> g >> b >> n;
	for (int i = 0; i <= n / r; i++)
	{
		for (int j = 0; j <= n / g; j++)
		{
			if ((i * r + j * g) <= n && (n - i * r - j * g) % b == 0)
			{
				ans++;
			}
		}
	}
	cout << ans << endl;
	cin >> n;
}
