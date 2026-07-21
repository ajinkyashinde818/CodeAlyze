#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<climits>
#include<map>
#include<string>
#include<functional>
#include<iomanip>
#include<deque>
#include<random>
#include<set>
#include<bitset>
#include<cassert>

using namespace std;
typedef long long ll;
typedef double lldo;
#define mp make_pair
#define pub push_back
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define chmax(x,y) x = max(x,y)
ll gcd(ll a, ll b) { if (a % b == 0) { return b; } else  return gcd(b, a % b); }
ll lcm(ll a, ll b) { if (a == 0) { return b; }return a / gcd(a, b) * b; }
template<class T>ll LBI(vector<T>& ar, T in) { return lower_bound(ar.begin(), ar.end(), in) - ar.begin(); }
template<class T>ll UBI(vector<T>& ar, T in) { return upper_bound(ar.begin(), ar.end(), in) - ar.begin(); }

ll n, A;
pair<ll, ll>a[400005] = {}, ans[200005] = {};
queue<ll> qa, qb;

int main() {
	cin >> n;
	rep(i, n) {
		cin >> A;
		a[i] = mp(A, 0);
	}
	rep(i, n) {
		cin >> A;
		a[i + n] = mp(A, 1);
	}
	stable_sort(a, a + 2 * n);
	rep(i, n) {
		if (a[i].second == 0 && a[i + n].second == 0)qa.push(i);
		if (a[i].second == 1 && a[i + n].second == 1)qb.push(i);
		if (a[i].second == 1 && a[i + n].second == 0)swap(a[i], a[i + n]);
		if (a[i].first == a[i + n].first) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	while (sz(qa)) {
		ll x = qa.front(), y = qb.front();
		qa.pop();
		qb.pop();
		if (a[x].first != a[y + n].first && a[y].first != a[x + n].first) {
			swap(a[x + n].first, a[y + n].first);
			swap(a[y], a[y + n]);
		}
		else {
			swap(a[x + n].first, a[y].first);
		}
	}
	rep(i, n)ans[i] = mp(a[i].first, a[i + n].first);
	stable_sort(ans, ans + n);
	rep(i, n)cout << ans[i].second << endl;
	return 0;
}
