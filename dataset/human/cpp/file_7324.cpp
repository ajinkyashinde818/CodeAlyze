#include <bits/stdc++.h>

using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;
using VVB = vector<VB>;
using VD = vector<double>;
using VVD = vector<VD>;
using VS = vector<string>;
using PII = pair<int, int>;
using VPII = vector<PII>;
using VL = vector<long long>;
using VVL = vector<VL>;

#define sz(var) (int)var.size()
#define REP(var, start, end) for(int var = start; var < (int)end; ++var)
#define REPC(var, start, end) for(int var = start; var <= (int)end; ++var)
#define CLEAR(var, with) memset(var, with, sizeof(var))
#define ALL(x) x.begin(), x.end()
#define LL long long
#define ULL unsigned long long
#define TIME cout << "Time elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << endl;

const LL INF = (LL)1e18;
int n;
VL cards, psum;
LL mindiff()
{
	LL ans = INF; LL sum = 0;
	for(int i = 1; i <= n - 1; ++i)
	{
		sum += cards[i];
		ans = min(ans, abs(sum - (psum[n] - psum[i])));
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifndef ONLINE_JUDGE
//	freopen("tmp.in", "r", stdin);
//	freopen("tmp.out", "w", stderr);
#endif
	cin >> n;

	cards.resize(n + 1); psum.resize(n + 1);
	REPC(i, 1, n) {
		 cin >> cards[i];
		psum[i] = cards[i] + psum[i - 1];
	}

	cout << mindiff() << endl;

	return 0;
}
