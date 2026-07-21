#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<iterator>
#include<complex>
#include<stack>
#include "stdio.h"
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const long long mod_const = 1e9+7;
using MIte = multimap<long, long, greater<long> >::iterator;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long N, C;
	cin >> N >> C;

	vector<long long> vx(N, 0);
	vector<long long> vv(N, 0);
	rep(i, N) cin >> vx[i] >> vv[i];

	long long ans1 = 0;
	vector<long long> vecans1(N, 0);
	ans1 = vv[0] - vx[0];
	{
		long long all = ans1;
		vecans1[0] = ans1;
		for (int i = 1; i != N; ++i) {
			all = all + vv[i] - (vx[i] - vx[i - 1]);
			ans1 = max(ans1, all);
			vecans1[i] = ans1;
		}
	}

	long long ans2 = 0;
	vector<long long> vecans2(N, 0);
	ans2 = vv[N - 1] - (C - vx[N - 1]);
	
	{
		long long all = ans2;
		vecans2[N - 1] = ans2;
		for (int i = N - 2; i != -1; --i) {
			all = all + vv[i] - (vx[i + 1] - vx[i]);
			ans2 = max(ans2, all);
			vecans2[i] = ans2;
		}
	}

	long long ans3 = 0;
	for (int i = 0; i != N - 1; ++i) {
		ans3 = max(ans3, vecans1[i] - vx[i] + vecans2[i + 1]);
	}

	long long ans4 = 0;
	for (int i = N - 1; i != 0; --i) {
		ans4 = max(ans4, vecans2[i] - (C - vx[i]) + vecans1[i - 1]);
	}

	long long ans = max({ ans1, ans2, ans3, ans4 });

	cout << ans << endl;

	return 0;
}
