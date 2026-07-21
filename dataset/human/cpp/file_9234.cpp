#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <cmath>
#include <iomanip>
#include <list>
#include <tuple>
#include <bitset>
#include <ciso646>
#include <cassert>

using namespace std;

#define int long long
#define double long double

typedef pair<int, int> P;
typedef tuple<int, int, int> T;

template<class T> string tostr(T x){stringstream o;o<<x;return o.str();}
template<class T> T sqr(T x){return x*x;}
template<class T> T mypow(T x,int n){T r=1;while(n>0){if(n&1)r=r*x;x=x*x;n>>=1;}return r;}

int toint(string s){int v; stringstream i(s);i>>v;return v;}
bool check(int y, int x, int h, int w){return y>=0&&x>=0&&y<h&&x<w;}
int gcd(int a,int b){return b ? gcd(b, a%b) : a;}
int lcm(int a,int b){return a / gcd(a, b) * b;}

#define REP(i,a,b)	for(int (i) = (a);i < (b);(i)++)
#define rep(i,n)	REP(i,0,n)
#define PER(i,a,b)	for(int (i) = (a-1);i >= (b);(i)--)
#define per(i,n)	PER(i,n,0)
#define each(i,n)	for(auto &i : n)
#define clr(a)		memset((a), 0 ,sizeof(a))
#define mclr(a)		memset((a), -1 ,sizeof(a))
#define all(a)		(a).begin(),(a).end()
#define sz(a)		(sizeof(a))
#define dump(val) 	cerr << #val " = " << val << endl;
#define dum(val)	cerr << #val " = " << val;
#define Fill(a,v)	fill((int*)a,(int*)(a+(sz(a)/sz(*(a)))),v)

const int dx[8] = { +1,+0,-1,+0,+1,+1,-1,-1 };
const int dy[8] = { +0,-1,+0,+1,-1,+1,-1,+1 };
const int mod = 1e9 + 7;
const int INF = 1e17 + 9;

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<string> a(n), b(m);

	rep(i, n) {
		cin >> a[i];
	}
	rep(i, m) {
		cin >> b[i];
	}

	bool in = false;

	rep(y, n)rep(x, n) {
		bool ok = true;
		rep(ty, m)rep(tx, m) {
			if (!check(y + ty, x + tx, n, n)) {
				ok = false;
				continue;
			}
			if (a[y + ty][x + tx] != b[ty][tx]) {
				ok = false;
			}
		}
		if (ok) in = true;
	}

	if (in) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}
