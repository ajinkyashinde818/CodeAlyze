#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <utility>
#include <functional>
#include <numeric>
#include <limits>

const long long int INF = 1 << 30;
const int V = 10;
struct edge { int to, cost; };
std::vector<edge>v[100];
typedef std::pair<int, int>p;

int main() {
	long long int n, a[200000], sum = 0;
	std::cin >> n;
	for (int i = 0;i < n;i++) {
		std::cin >> a[i];
		sum += a[i];
	}
	long long int nSum = 0, ans = 1000000000000000;
	for (int i = n - 1;i > 0;i--) {
		sum -= a[i];
		nSum += a[i];
		if (llabs(sum - nSum) < ans) {
			ans = llabs(sum - nSum);
		}
	}
	std::cout << ans << std::endl;
	return 0;
}
