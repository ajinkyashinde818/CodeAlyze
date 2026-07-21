#include <cstdlib>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

#define sz(X) ((int)(X).size())
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define all(X) (X).begin(),(X).end()
#define FOR(i, a, n) for(int i=(a), __ ## i=(n); i<__ ## i; i++)
#define REP(I,N) FOR(I,0,N)
#define PR(X) cout<<#X<<" = "<<(X)<<" "
#define PRL cout<<endl
#define PRV(X) {cout<<#X<<" = {";REP(__prv,sz(X)-1)cout<<(X)[__prv]<<",";if(sz(X))cout<<*(X).end();cout<<"}"<<endl;}

template<class T> ostream &operator<<(ostream &os, const vector<T> &vec)
{
	os << '{';
	REP(i, sz(vec))
	{
		os << vec[i];
		if (i + 1 != sz(vec))
			os << ',';
	}
	os << '}';
	return os;
}

template<class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &par)
{
	os << '(' << par.X << ',' << par.Y << ')';
	return os;
}

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<unsigned long long> VULL;
typedef vector<vector<int>> VVI;
typedef queue<int> QI;

int gcd(int x, int y)
{
	return y ? gcd(y, x % y) : abs(x);
}

template<class T> T sqr(T x)
{
	return x * x;
}

LL a[100001];
LL b[100001];
LL sa[100001];
LL sb[100001];
map<LL, bool> masked;
map<LL, int> mask;
int num;

int add(LL n)
{
	if (!masked[n])
	{
		mask[n] = num++;
		masked[n] = true;
	}
	return mask[n];
}

bool used[100001];

int main()
{
	ios::sync_with_stdio(false);
	num = 0;
	int N;
	cin >> N;
	REP(i, N)
	{
		cin >> a[i + 1];
		a[0] ^= a[i + 1];
		sa[i + 1] = a[i + 1];
	}
	sa[0] = a[0];
	REP(i, N)
	{
		cin >> b[i + 1];
		b[0] ^= b[i + 1];
		sb[i + 1] = b[i + 1];
	}
	sb[0] = b[0];

	sort(sa, sa + N + 1);
	sort(sb, sb + N + 1);

	REP(i, N + 1)
	{
		if (sa[i] != sb[i])
		{
			cout << -1;
			return 0;
		}
	}

	VVI edge(N + 1);
	VVI back(N + 1);
	FOR(i, 1, N + 1)
	{
		if (a[i] != b[i])
		{
			int x = add(a[i]);
			int y = add(b[i]);
			edge[x].pb(y);
			back[y].pb(x);
		}
	}

	int comps = 0;
	int res = 0;
	REP(i, num)
	{
		if (used[i])
			continue;
		comps++;
		QI que;
		que.push(i);
		used[i] = true;
		int ed = 0;
		while (!que.empty())
		{
			int u = que.front();
			que.pop();

			ed += sz(edge[u]);

			REP(j, sz(edge[u]))
			{
				if (!used[edge[u][j]])
				{
					used[edge[u][j]] = true;
					que.push(edge[u][j]);
				}
			}
			REP(j, sz(back[u]))
			{
				if (!used[back[u][j]])
				{
					used[back[u][j]] = true;
					que.push(back[u][j]);
				}
			}
		}
		res += ed;
	}

	res += comps - 1;
	if (!masked[a[0]])
	{
		add(a[0]);
		res++;
	}
	if (!masked[b[0]])
	{
		add(b[0]);
		res++;
	}

	cout << res;

	return 0;
}
