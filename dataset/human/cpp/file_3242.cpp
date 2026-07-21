#include<iostream>
#include<vector>
#include<utility>
#include<deque>
#include<algorithm>
#include <iomanip>
#include<cmath>
#include<numeric>

using namespace std;
using ll = long long int;
constexpr int INF = 1 << 29;
constexpr ll MOD = ll(1e9 + 7);
int n, m=0;
ll tmp = -pow(10, 9) - 1;
vector<ll> a;


int main(void) {
	cin >> n;
	a = vector<ll>(n);
	ll ret = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < 0)
			m++;
		ret += abs(a[i]);
		if (abs(a[i]) < abs(tmp))
			tmp = a[i];
	}
	if (m % 2 != 0)
		ret -= 2 * abs(tmp);
	cout << ret << endl;
}
