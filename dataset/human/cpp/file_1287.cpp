#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <set>
#include <tuple>
#include <algorithm>
#include <memory>
#include <numeric>
#include <queue>
#include <functional>
#include <cmath>
#include <cstring>
#include <map>
#include <unordered_map>
#include <sstream>
#include <iomanip>

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;

const ll INF = 1LL << 60;
const ll MOD = 1000000007;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll R, G, B, N;
	cin >> R >> G >> B >> N;

	ll ans = 0;

	for (ll r = 0; r <= N; ++r)
	{
		ll n1 = N - r * R;
		if (n1 < 0) break;
		for (ll g = 0; g <= N; ++g)
		{
			ll n2 = n1 - g * G;
			if (n2 < 0) break;

			if (n2 % B == 0) ans++;
		}
	}

	cout << ans << endl;

	//system("pause");
}
