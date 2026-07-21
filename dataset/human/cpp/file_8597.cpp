#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <numeric>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <fstream>
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef complex<double> Point;

#define PI acos(-1.0)
#define EPS 1e-10
const ll INF = 1e9 + 7;
const ll MOD = 1e9 + 7;

#define FOR(i,a,b) for(long long i=(a);i<(b);i++)
#define REP(i,N) for(long long i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )
#define fi first
#define se second

int m, n;
string a[100010], b[100010];
bool f = 0;

int main(){
	cin >> n >> m;
	REP(i, n){
		cin >> a[i];
	}
	REP(i, m){
		cin >> b[i];
	}
	REP(i, n - m + 1){
		REP(j, n - m + 1){
			bool g = 1;
			REP(k, m){
				REP(l, m){
					if (a[i + k][j + l] != b[k][l])g = 0;
				}
			}
			f |= g;
		}
	}
	if (f)cout << "Yes" << endl;
	else cout << "No" << endl;
}
