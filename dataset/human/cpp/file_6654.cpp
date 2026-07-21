#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <math.h>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> Q;

const ll mod = 1000000007;
const ll INF = 1000000000000;

ll dp[200010], n, num[200010], kai[200010];
string s;

int main()
{
	cin >> n >> s;
	kai[0] = 1;
	for (int i = 1; i <= 200005; i++)
	{
		kai[i] = kai[i - 1] * i % mod;
	}

	if (s[0] == 'W')
	{
		cout << 0 << endl;
		return 0;
	}

	num[0] = 1;
	dp[0] = 1;
	for (int i = 1; i < 2 * n; i++)
	{
		if (s[i] == 'W')
		{
			if (num[i - 1] % 2 == 0)
			{
				num[i] = num[i - 1] - 1;
				(dp[i] = dp[i - 1] * num[i - 1] % mod) %= mod;
			}
			else
			{
				num[i] = num[i - 1] + 1;
				dp[i] = dp[i - 1];
			}
		}
		else
		{
			if (num[i - 1] % 2 == 0)
			{
				num[i] = num[i - 1] + 1;
				dp[i] = dp[i - 1];
			}
			else
			{
				num[i] = num[i - 1] - 1;
				(dp[i] = dp[i - 1] * num[i - 1] % mod) %= mod;
			}
		}
	}

	if (num[2 * n - 1] == 0)
	{
		cout << dp[2 * n - 1] * kai[n] % mod << endl;
	}
	else
	{
		cout << 0 << endl;
	}

	int www;
	cin >> www;
}
