#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

long long n, a, mn=1e9, sum, c;
int main() {
	cin >> n;
	while(n--) {
		scanf("%lld", &a);
		c += (a<0);
		a = abs(a);
		sum += a;
		mn = min(mn, a);
	}
	cout << sum - c%2 * 2 * mn;
	return 0;
}
