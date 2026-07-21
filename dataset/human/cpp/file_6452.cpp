#include<iostream>
#include<map>
#include<unordered_map>
#include<set>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long double ld;
#define mp make_pair
#define pb push_back

#define rep(i, N) for(ll i = 0; i < N; i++)
#define repa(i, a, N) for(ll i = a; i < N; i++)
#define repr(i, N) for(ll i = N-1; i >= 0; i--)

#define drep(i, N, j, M) rep(i, N) rep(j, M)
#define trep(i, N, j, M, k, L) rep(i, N) rep(j, M) rep(k, L)

const ll mod = 1e9 + 7;
// const ll mod = 998244353;

const ll LLMAX = numeric_limits<long long>::max();

void No() {
	cout << "No" << endl;
}

void Yes() {
	cout << "Yes" << endl;
}


int main() {
	ll N;
	cin >> N;

	vector<bool> B(2 * N);
	rep(i, 2 * N) {
		char c; cin >> c;
		if (c == 'B') {
			B[i] = true;
		}
		else {
			B[i] = false;
		}
	}

	ll rem = 0;
	ll ans = 1;

	rep(i, 2 * N) {
		// 前のを使用する場合
		if ((B[i] && rem % 2 == 1) ||
			(!B[i] && rem % 2 == 0)) {
			if (rem == 0) {
				cout << 0 << endl;
				return 0;
			}
			ans *= rem;
			ans %= mod;
			rem--;
		}
		// 後回しにする場合
		else {
			rem++;
		}
	}

	if (rem > 0) {
		ans = 0;
		cout << ans << endl;
		return 0;
	}

	rep(i, N) {
		ans *= (i + 1);
		ans %= mod;
	}

	cout << ans << endl;

	return 0;
}
