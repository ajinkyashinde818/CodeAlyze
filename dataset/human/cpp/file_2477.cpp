#include <iostream>
#include <cmath>
#include <limits>
using namespace std;
typedef long long ll;

int main() {
	ll total, min = numeric_limits<int>::max(); ll check = 0;
	ll n; cin >> n;
	for (ll i = 0; i < n; i++){
		ll num; cin >> num;
		if (abs(num) < abs(min)) min = abs(num);
		if (num < 0) check++;
		total += abs(num);
	}
	if (check & 1) {
		total -= 2*min;
	}
	cout << total;
	return 0;
}
