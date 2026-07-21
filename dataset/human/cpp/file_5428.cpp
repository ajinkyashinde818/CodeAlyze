#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
#include<vector>
#include<iomanip>
using namespace std;
typedef long long ll;
ll inf = 100000000;
ll v[205];
ll x[20000005];
ll a[10000005];
ll dp[20005][10005];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
typedef pair<ll, ll> P;
double q[200005];
ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}
string s[2000005];
P p[2000005];
int main() {
	int n, k;
	cin >> n >> k;
	if (n < 10) {
		cout << k + 100 * (10 - n) << endl;
		return 0;
	}
	cout << k << endl;
	return 0;
}
