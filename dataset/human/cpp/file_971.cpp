#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<sstream>
#include<complex>
#include<functional>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<stack>
#include<set>

using namespace std;
#define endl '\n'
#define eb emplace_back
#define fst first
#define scd second
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define YES(n) cout << ((n) ? "YES" : "NO" ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No" ) << endl

constexpr int MOD = 1000000007;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<ll> vl;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

// value
int R, G, B, N;

void solve() {

	cin >> R >> G >> B >> N;
	ll cnt = 0;
	for (int i = 0; R * i <=N; i++) {
		for (int j = 0; R * i + G * j <= N; j++) {
			int b = N - R * i - G * j;
			if (b % B == 0) {
				cnt++;
			}
		}
	}
	
	cout << cnt << endl;

	return;

}

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	solve();

	return 0;

}
