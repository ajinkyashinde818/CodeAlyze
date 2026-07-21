#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <vector>
#include <utility>
#include <time.h>
#include <set>
#include <unordered_set>
#include <list>
#include <iterator>
#include <time.h>
#include <chrono>
#include <deque>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <climits>
#include <tuple>
#include <map>
using namespace std;

#define ll long long
#define ldb long double

ll mod(ll a, ll b)
{
	return (b + (a % b)) % b;
}

ll subMod(ll a, ll b, ll M)
{
	return mod((mod(a, M) - mod(b, M)), M);
}

ll dayofweek(ll d, ll m, ll y)
{
	static ll t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
	y -= m < 3;
	return (y + y / 4 - y / 100 +
		y / 400 + t[m - 1] + d) % 7;
}

void test()
{

}


void solve()
{
	ll n, r;
	cin >> n >> r;

	if (n >= 10)
	{
		cout << r;
	}
	else
	{
		cout << r + 100 * (10 - n);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//test();

	solve();

	return 0;
}
