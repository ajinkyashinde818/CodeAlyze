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
typedef std::vector<int> VI;

#define FOR(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR1(i,n) for(int (i)=1;(i)<(n);(i)++)
#define eFOR(i,n) for(int (i)=0;(i)<=(n);(i)++)
#define eFOR1(i,n) for(int (i)=1;(i)<=(n);(i)++)
#define SORT(i) sort((i).begin(),(i).end())

int main() {

	int n;
	cin >> n;
	vector<ll> a(n);
	FOR(i, n)cin >> a[i];
	FOR1(i, n)a[i] += a[i - 1];
	ll sum = a[n - 1], ans = 10e9;
	FOR(i, n - 1) {
		ans = min(ans, abs(sum - a[i] * 2));
	}
	cout << ans << endl;

	return 0;
}
