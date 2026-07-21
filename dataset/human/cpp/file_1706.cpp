#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <cassert>
#include <complex>
#include <iomanip>
#include <random>

using namespace std;

typedef long long ll;
#define int ll

const int M = 998244353;
#define msum(a, b) ((a) + (b) >= M ? (a) + (b) - M : (a) + (b))
#define msub(a, b) ((a) - (b) < 0 ? (a) - (b) + M : (a) - (b))
#define mmult(a, b) (((a) * (b)) % M)

typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mmin(a, b) a = min(a, (b))
#define mmax(a, b) a = max(a, (b))
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define SZ(a) ((int)(a).size())
#define watch(x) cout << (#x) << " = " << (x) << endl;

const double PI = 2 * acos(0.0);
const int oo = 1e9 + 100;
const string DIGITS = "0123456789";
const string ALPH = "abcdefghijklmnopqrstuvwxyz";


#define N 100000

vector <int> g[N];


signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;

	

	int p = 2, k = 1;

	while (k < n)
	{
		k += p;
		p++;
	}

	if (k != n)
	{
		cout << "No";
	}
	else
	{
		int o = 1;
		cout << "Yes" << endl;
		for (int i = 1; i <= p; i++)
		{
			for (int j = i + 1; j <= p; j++)
			{
				g[i].push_back(o);
				g[j].push_back(o);
				o++;
			}
		}
		cout << p << endl;
		for (int i = 1; i <= p; i++)
		{
			cout << g[i].size() << " ";
			for (int j = 0; j < g[i].size(); j++)
				cout << g[i][j] << " ";
			cout << endl;
		}
	}

}
