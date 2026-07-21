#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
#include <cctype>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <bitset>
#include <complex>
#include <fstream>
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
typedef vector<int> vint;
typedef pair<int, int> pint;
#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
template<class T> T RoundOff(T a){ return int(a+.5-(a<0)); }
template<class T, class C> void chmax(T& a, C b){ if(a < b) a = b; }
template<class T, class C> void chmin(T& a, C b){ if(b < a) a = b; }
template<class T, class C> pair<T, C> mp(T a, C b){ return make_pair(a, b); }

typedef complex<double> P;
struct Circle
{
	P p;
	double r;
};

// OÏ
double cross(P a, P b)
{	return a.real() * b.imag() - b.real() * a.imag();	}

// àÏ
double dot(P a, P b)
{	return a.real() * b.real() + a.imag() * b.imag();	}

// _ÆüªÌ£
double dist(P a, P b, P c)
{
	if(dot(b - a, c - a) < EPS) return abs(c - a);
	if(dot(a - b, c - b) < EPS) return abs(c - b);
	
	return abs(cross(b - a, c - a)) / abs(b - a);
}

bool Hit(Circle c, P a, P b)
{
	return dist(a, b, c.p) <= c.r;
}

bool isInCircle(Circle c, P x)
{
	return abs(c.p - x) < c.r;
}

int main()
{
    int n, m;
	while(cin >> n && n)
	{		
		vector<Circle> circle(n);
		rep(i, n) cin >> circle[i].p.real() >> circle[i].p.imag() >> circle[i].r;
		
		cin >> m;
		while(m--)
		{
			P t, s;
			cin >> t.real() >> t.imag() >> s.real() >> s.imag();
			
			rep(i, n)
			{
				if(Hit(circle[i], t, s) && !(isInCircle(circle[i], t) && isInCircle(circle[i], s)))
				{
					cout << "Safe" << endl;
					break;
				}
				else if(i + 1 == n)
				{
					cout << "Danger" << endl;
				}
			}
		}
	}
}
