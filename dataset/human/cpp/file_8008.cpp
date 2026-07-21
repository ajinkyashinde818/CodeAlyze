#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	auto a = vector<long long int>(n + 1);
	for(auto i = 1; i <= n; ++i){
		cin >> a[i];
		a[i] += a[i - 1];
	}
	long long int ans = 10000000000;
	for(auto i = 1; i <= n - 1; ++i){
		ans = min(ans, abs(a[n] - a[i] * 2));
	}
	cout << ans << endl;
	return 0;
}
