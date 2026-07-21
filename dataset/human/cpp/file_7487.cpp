#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<cmath>
#include<list>
#include<set>
#include<map>

using namespace std;
long long MOD = 1000000007LL;
const double PI = 3.14159265358979323846;
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define endl "\n"

int main() {
	int N;
	cin >> N;
	vector<long long> a(N);

	long long sumA = 0;
	long long sumS = 0;
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
		sumS += a[i];
	}
	sumA += a[0];
	sumS -= a[0];

	long long ans = abs(sumA - sumS);
	for (int i = 1; i < N - 1; ++i) {
		sumA += a[i];
		sumS -= a[i];

		ans = min(ans, abs(sumA - sumS));
	}

	cout << ans << endl;
	return 0;
}
