#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define mod 1000000007
#define ll long long int
#define pb(x) push_back(x)
#define MP(x,y) make_pair(x,y)

using namespace std;

ll power(ll a, ll b, ll m)
{
	if (b == 0)
		return(1);
	ll sol = power(a, b / 2, m);
	sol = (sol * sol) % m;
	if (b % 2 == 1)
		sol = (sol * a) % m;
	return(sol);
}
ll gcd(ll a, ll b)
{
	if (a % b == 0)
		return b;
	else
	{
		return gcd(b, a % b);
	}
}
void solve()
{
	ll a, b, c, n,sol=0;
	cin >> a >> b >> c >> n;
	for (int i = 0; i <= n; i++)
	{
		int x = n - i * a;
		if (x < 0)
			continue;
		for (int j = 0; j <= n; j++)
		{
			int y = x - j * b;
			if (y < 0)
				continue;
			if (y % c == 0)
				sol++;
		}
	}
	cout << sol;
}
int main()
{
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	return(0);
}
