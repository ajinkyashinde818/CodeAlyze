#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <numeric>
#include <regex>
#include <tuple>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define MOD 1000000007 // 10^9 + 7
#define INF 1000000000 // 10^9
#define LLINF 1LL<<60


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int R, G, B, N; cin >> R >> G >> B >> N;

	ll cnt = 0LL;
	for (int r = 0; R*r <= N; r++) {
		for (int g = 0; G*g <= N; g++) {
			ll num = N - R * r - G * g;
			if (0 <= num && num%B==0) cnt++;
		}
	}
	cout << cnt << endl;

	return 0;
}
