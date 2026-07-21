#include <iostream>
#include <array>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>
#include <random>
#include <queue>
#include <iomanip>
#include <functional>
#include <climits>
#include <tuple>
#include <unordered_map>
#include <limits>
#include <functional>
#include <cassert>
#include <numeric>
#include <bitset>
#include <set>

#define FOR(x,n) for(int x = 0; x < n; x++)
#define INPUT(x) scanf("%d",&x)
#define PUT(x) printf("%d\n",x)
#define DPUT(x) printf("%.15lf\n",x)
#define GET(x,y) std::get<x>(y)
#define CHMAX(x,y) x = std::max(x,y)
#define CHMIN(x,y) x = std::min(x,y)
#define SP_END (i != n - 1 ? ' ' : '\n') ;

using namespace std;

using ll = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vll = std::vector<ll>;
using vpll = std::vector<pll>;
using vpii = std::vector<pii>;
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using vvpii = std::vector<vpii>;
using vch = std::vector<char>;
using vvch = std::vector<vch>;
using tiii = std::tuple<int, int, int>;

const ll mod197 = 1000000007LL;
const ll INF = 10000000000LL;

const double PI11 = 3.14159265359;

const int dis[5] = { 0,1,0,-1,0 };

const int disD[4] = { 0,1,1,0 };
const int disLD[3] = { 0,1,0 };

const char disC[4] = { 'U','D','R','L' };
const char disY[4] = { -1,1,0,0 };
const char disX[4] = { 0,0,1,-1 };

ll x[100000] = {}, v[100000] = {};
ll right[100000] = {}, left[100000] = {};

int main(void)
{
	ll N, C;
	cin >> N >> C;
	ll answer = 0;

	FOR(i, N) {
		cin >> x[i] >> v[i];
	}

	ll v_sum = 0;
	FOR(i, N) {
		v_sum += v[i];
		if(i == 0)
			::right[i] = max(::right[i], v_sum - x[i]);
		else
			::right[i] = max(::right[i - 1], v_sum - x[i]);
		CHMAX(answer, ::right[i]);
	}

	v_sum = 0;
	for (int i = N - 1; i >= 1; i--) {
		v_sum += v[i];
		CHMAX(answer, ::right[i - 1] + v_sum - (C - x[i]) * 2);
	}

	v_sum = 0;
	for (int i = N - 1; i >= 0; i--) {
		v_sum += v[i];
		if (i == N - 1)
			::left[i] = max(::left[i], v_sum - (C - x[i]));
		else
			::left[i] = max(::left[i + 1], v_sum - (C - x[i]));
		CHMAX(answer, ::left[i]);
	}

	v_sum = 0;
	for (int i = 0; i <= N - 2; i++) {
		v_sum += v[i];
		CHMAX(answer, ::left[i + 1] + v_sum - (x[i]) * 2);
	}

	cout << answer << endl;

	return 0;
}
