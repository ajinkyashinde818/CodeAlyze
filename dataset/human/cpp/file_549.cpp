#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<stack>
#include<queue>
#include<deque>
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
#define rSORT(i) sort((i).begin(),(i).end(), greater<int>());
#define YES(i) cout << ((i) ? "Yes" : "No") << endl;
#define F first
#define S second
constexpr auto INF = 1000000000;
constexpr auto LLINF = 9223372036854775807;
constexpr auto mod = 1000000007;
int main() {

	int r, g, b, n;
	cin >> r >> g >> b >> n;

	int R = n / r;

	int ans = 0;
	eFOR(i, R) {
		int nr = n - i * r;
		if (nr == 0) {
			ans++;
			continue;
		}
		int G = nr / g;
		eFOR(j, G) {
			int ng = nr - j * g;
			if (ng % b == 0) {
				ans++;
				continue;
			}
		}
	}

	cout << ans << endl;

	return 0;
}
