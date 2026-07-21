#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;

const ll INF = (1e+12) + 1;

int main() {
	ll n, a, m_ma = INF, sum = 0, count = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		if (a < 0) count++;
		m_ma = min(m_ma, abs(a));
		sum += abs(a);
	}
	if (count % 2) sum -= 2 * abs(m_ma);
	cout << sum << endl;
	return 0;
}
