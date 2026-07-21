#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<sstream>
#include<iomanip>
#include<limits>
#include<deque>
#include<map>
#include<list>
#include<set>
#include <unordered_set>
#include<vector>
#include<cmath>
#include<cstdio>
#include<memory>
#include<bitset>
#include<stack>
#include <functional>
#include <queue>
#include <regex>

using namespace std;

constexpr int MOD = 1000000007;
constexpr int INF = 1050000000;

#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl

#define Tof(x) (x) ? Yes : No
#define TOF(x) (x) ? YES : NO
#define tof(x) (x) ? yes : no

using ll = long long;


/*vectorの要素を全部確認するやつだよ。


for (vector<int>::iterator itr = ans.begin(); itr != ans.end(); ++itr) {
	cout << *itr << " ";
}


*/


/*for文でx,yを上下左右確認するやつだよ。

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };


for (int i = 0; i < 4; i++) {
	int ny = y + dy[i];
	int nx = x + dx[i];
}
*/

/*繰り返し二乗法だよ。modもとってくれるよ。n^kをmodで割った余りでやってくれるよ。

ll POW_MOD(ll n, ll k, ll mod) {
	ll r = 1;

	for (; k > 0; k >>= 1) {
		if (k & 1) {
			r = (r * n) % mod;
		}
		n = (n * n) % mod;
	}
	return r;
}


*/

/*2重for文書くのめんどくなった時用だよ。

for (int i = 0; i < h; i++) {
	for (int j = 0; j < w; j++) {

	}
}

*/

int main(void) {
	int r, g, b, n; cin >> r >> g >> b >> n;


	ll ans = 0;

	for (int i = 0; i <= n; i++) {
		int x = i * r;
		for (int j = 0; j <= n; j++) {
			int y = j * g;


			if (x + y > n) { continue; }

			if ((n - (x + y)) % b == 0) { ans++; }
		}
	}




	cout << ans << endl;









}
