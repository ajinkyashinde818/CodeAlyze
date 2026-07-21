#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<queue>
#include<deque>
#include<stack>
#include<cstdio>
#include<utility>
#include<set>
#include<list>
#include<cmath>
#include<stdio.h>
#include<string.h>
#include<iomanip>
using namespace std;
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define NREP(i, n) FOR(i, 1, n)
using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, pii>;
const ll dx[4] = { 0, -1, 1, 0 };
const ll dy[4] = { -1, 0, 0, 1 };
const int INF = 1e9 + 7;
int gcd(int x, int y) {
	if (x < y)swap(x, y);
	if (y == 0)return x;
	return gcd(y, x%y);
}
////////////////////////////////////////

int main() {
	int r, g, b, n;
	cin >> r >> g >> b >> n;
	int ans = 0;
	for (int i = 0; i <= n/r+1; ++i) {
		for (int j = 0; j <= n/g+1; ++j) {
			if (i*r+j*g<=n&&(n - i * r - j * g) % b == 0 && (n - i * r - j * g) / b <= 3000) {
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
