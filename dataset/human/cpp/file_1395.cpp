#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <list>
#include <unordered_set>
#include <tuple>
#include <cmath>
#include <limits>
#include <type_traits>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <regex>
#include <random>
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define rep(i,n)for(ll i=0;i<n;++i)
#define exout(x) printf("%.10f\n", x)
const double pi = acos(-1.0);
const ll MOD = 1000000007;
const ll INF = 1e10;
const ll MAX_N = 1010;

ll dx[4] = { 0,0,-1,1 };
ll dy[4] = { -1,1,0,0 };
char c[310][310];
ll dp[101];

//long longしか使わない
//素数は1より大きい
//lower_boundは指定したkey以上の要素の一番左のイテレータをかえす
//upper_boundは指定したkeyより大きい要素の一番左のイテレータをかえす
int main() {
	ll r, g, b, n;
	cin >> r >> g >> b >> n;
	ll ans = 0;
	rep(i, n/r+1) {
		rep(j, n/g + 1) {
			ll res = n - i * r - j * g;
			if (0 <= res && res%b==0)ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
