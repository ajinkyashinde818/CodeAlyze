#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <iomanip>
#include <math.h>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <functional>

using namespace std;

typedef long long int ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;

#define FOR(i,n,m) for(ll i=(ll)(m);i<(ll)(n);++i)
#define REP(i,n) FOR(i,n,0)
#define IREP(i,n) for(ll i=(ll)(n);i>=0;--i)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int main()
{
	int N;
	cin >> N;

	REP(i, 1000)
	{
		int n = i*(i + 1) / 2;
		if (n > N)break;
		if (n < N)continue;
		cout << "Yes" << endl;
		cout << i + 1 << endl;

		//! 未だ使用していない数
		int x = 1;
		vector< vector<int> >v;
		REP(j, i + 1)
		{
			vector<int> p;
			REP(k, j)
			{
				p.push_back(v[k][j - 1]);
			}
			//! i個に足りない分補充
			REP(k, i - j)
			{
				p.push_back(x++);
			}

			//! 構成した部分集合を出力
			cout << i;
			REP(k, i)
			{
				cout << " " << p[k];
			}
			cout << endl;
			v.push_back(p);
		}
		return 0;
	}
	cout << "No" << endl;
	return 0;
}
