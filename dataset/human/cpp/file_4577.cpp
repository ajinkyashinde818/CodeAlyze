#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	int n, r; cin >> n >> r;
	if (n < 10) r += 100 * (10 - n);
	cout << r << endl;
	return 0;
}
