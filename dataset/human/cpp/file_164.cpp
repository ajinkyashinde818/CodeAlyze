#include<iostream>
#include<map>
#include<string.h>
#include<queue>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<cstdlib>
#include<math.h>
#include<set>
#include<array>
using namespace std;

template<class T>inline bool chmax(T&a, T b) { if (a < b) { a = b; return 1; }return 0; }
template<class T>inline bool chmin(T&a, T b) { if (a > b) { a = b; return 1; }return 0; }



#define rep(n) for(int i=0;i<n;i++)
typedef pair<int, int> pii;

typedef long long ll;
typedef pair<ll, ll>pll;
const int MOD = 1000000007;
const int INF = 1 << 29;


int main() {
	
	int a, b, c,n;
	int cnt = 0;
	cin >> a >> b >> c >> n;
	for (int i = 0; a*i<=n; i++) {
		for (int j = 0; a*i + b * j <= n; j++) {
			if ((n - a * i - b * j) % c == 0) {
				cnt++;
				//cout << i << j ;
			}
		}
	}
	cout << cnt << endl;
	return 0;
	
}
