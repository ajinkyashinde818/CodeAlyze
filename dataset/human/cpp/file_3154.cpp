#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<stack>
#include<queue>
#include<map>
#include<set>

using namespace std;

typedef long long ll;
typedef vector<int> VI;

#define FOR(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR1(i,n) for(int (i)=1;(i)<(n);(i)++)
#define eFOR(i,n) for(int (i)=0;(i)<=(n);(i)++)
#define eFOR1(i,n) for(int (i)=1;(i)<=(n);(i)++)
#define SORT(i) sort((i).begin(),(i).end())
constexpr auto INF = 1000000000;
constexpr auto LLINF = 9223372036854775807;
constexpr auto mod = 1000000007;

ll gcd(ll a, ll b) {
	while (1) {
		if (a < b) swap(a, b);
		if (!b) break;
		a %= b;
	}
	return a;
}

int main() {

	int n;
	cin >> n;
	bool zero = 0;
	int cnt = 0;
	ll mn = LLINF, sum = 0;
	FOR(i, n){
		ll b;
		cin >> b;
		if (b == 0)zero = 1;
		if (b < 0)cnt++;
		sum += abs(b);
		mn = min(mn, abs(b));
	}
	if (zero)cout << sum << endl;
	else if (cnt % 2 == 1)cout << sum - mn * 2 << endl;
	else cout << sum << endl;

	return 0;
}
