#include<iostream>
#include<climits>
#include<vector>
#include<list>
#include<functional>
#include<algorithm>
#include<string>
#include<cmath>
#include<complex>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<tuple>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;





int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<ll> sum(N + 1);
	sum[0] = 0;
	int nonpos_cnt = 0;
	int mn = 1000000000;
	REP(i, N) {
		int a;
		cin >> a;
		if (a <= 0) {
			nonpos_cnt++;
			a = -a;
		}
		mn = min(mn, a);
		sum[i + 1] = sum[i] + a;
	}
	ll res = sum[N];
	if (nonpos_cnt % 2) res -= 2 * mn;
	cout << res << "\n";
	
	return 0;
}
