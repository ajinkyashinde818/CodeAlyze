#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<iomanip>
#include<stack>
#include<string.h>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define sz(a) (int)a.size()
using namespace std;

ll INF = 1LL << 60;

int main() {
	int n;
	cin >> n;
	vector<ll> a(n);

	ll s = 0, ar = 0;
	rep(i, n) {
		if (i == 0) {
			cin >> a[i];
			s += a[i];
		}
		else {
			cin >> a[i];
			ar += a[i];
		}
	}
	ll ans = INF;
    ans=min(ans,abs(ar-s));
	rep(i, n - 2) {
		s += a[i + 1];
		ar -= a[i + 1];
		ans = min(ans, abs(ar - s));
	}
	cout << ans << endl;
}
