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
#include <time.h>
#include <tuple>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef complex<double> Point;

#define PI acos(-1.0)
#define EPS 1e-10
const ll INF = (1LL << 60) - 1;
const ll MOD = 1e9 + 7;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,N) for(int i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )
#define fi first
#define se second
#define N_SIZE (1LL << 20)
#define NIL -1
#define MAX_N 100100 * 3

int n, m;
int cnt[200010];
int ccnt[200010];
vector<int> vi;

int main() {
	cin >> n >> m;
	rep(i, m) {
		int num;
		cin >> num;
		cnt[num] = 1;
		ccnt[num] = 1;
		vi.push_back(num);
	}
	reverse(ALL(vi));
	rep(i, vi.size()) {
		if (ccnt[vi[i]])cout << vi[i] << endl;
		ccnt[vi[i]] = 0;
	}
	rep(i, n) {
		if (cnt[i + 1] == 0)cout << i + 1 << endl;
	}
}
