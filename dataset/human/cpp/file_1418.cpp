#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <iomanip>
#include <deque>
#include <list>
#include <cassert>
#include <complex>
#include <bitset>
#include <deque>


using namespace std;
typedef long long ll;
#define int ll
typedef long double ld;
typedef vector<int> vi;
typedef vector<ld> vld;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
#define mmin(a, b) a = min(a, (b))
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define SZ(a) ((int)(a).size())
#define watch(x) cout << (#x) << " = " << (x) << endl;


const int N = 1 << 17, oo = 1e9 + 10, A = 201, B = 100;
const ll M = 998244353, x = 137;





bool check(int v)
{
	int l = 0, r = v + 10;
	while (r - l > 1)
	{
		int m = (l + r) >> 1;
		if (m * (m - 1) / 2 >= v)
			r = m;
		else
			l = m;
	}

	return r * (r - 1) / 2 == v;
}



vvi blocks;


void add(int ind, int v)
{
	blocks[ind].push_back(v);
}


signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;

	if (!check(n))
	{
		cout << "No\n";
		return 0;
	}

	cout << "Yes\n";

	int K = 1;
	for (int i = 1; i <= n; ++i)
		if (check(i))
			K++;

	cout << K << '\n';
	blocks.resize(K + 1);
	int l = 1, r = 2;

	for (int i = 1; i <= n; ++i)
	{
		add(l, i);
		add(r++, i);
		
		if (r == K + 1)
		{
			l++;
			r = l + 1;
		}
	}

	for (int i = 1; i <= K; ++i)
	{
		cout << SZ(blocks[i]) << ' ';
		for (int v : blocks[i])
			cout << v << ' ';

		cout << '\n';
	}
}
