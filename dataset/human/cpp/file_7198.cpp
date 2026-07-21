#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <algorithm>
#include <array>
#include <complex>
#include <string>
#include <utility>
#include <map>
#include <queue>
#include <list>
#include <functional>
#include <numeric>
#include <stack>
#include <tuple>

using namespace std;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
const int INF = 100000000;
const long long LINF = 1000000000000000000;
const int MOD = (int)1e9 + 7;
using pii = std::pair<int, int>;
#define SORT(v) std::sort(v.begin(), v.end())

int main(void) {
	int n;
	long long sum = 0, sum_i = 0, ans = LINF;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n;++i) {
		cin >> a[i];
		sum += a[i];
	}
	
	for (int i = 0; i < n; ++i) {
		sum_i += a[i];
		if(i+1<n)ans = min(ans,abs(2 * sum_i - sum));
		
	}
	cout << ans << endl;
	return 0;
}
