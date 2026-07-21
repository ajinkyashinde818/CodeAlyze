#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <functional>
#include <string>
#include <cstdlib>
#include <numeric>
#include <cstdbool>
#include <map> 
#include<set>
#include<queue>

typedef long long ll;


#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1000000000000000;
const ll inf = -1e18;
typedef pair<int, int> P;
ll ma = 1000000000 + 7;
ll h, w, n,k,m; string s,t;
char maze[60][60];
int dis[101][101]; int graph[50][50]; bool vis[50];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll x, ll y) {
	if (x % y == 0) return y;
	return gcd(y, x % y);

}
ll lcm(ll a,ll b) {
	ll g = gcd(a, b);
	return a / g * b;
}
int main() {
	ll r, g, b; ll cnt = 0;
	cin >> r >> g >> b >> n;
	for (int i = 0; i <= n; i+=r) {
		for (int j = 0; j <= n; j+=g) {
			if ((n - i - j)%b == 0&&(n-i-j)<=n&&(n-i-j)>=0) {
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}
