#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

typedef long long ll;

int main (int argc, char* argv[]) {
	ll n;
	cin >> n;
	ll abs_sum = 0;
	ll smallest_abs_val = numeric_limits<ll>::max();
	ll total_negatives = 0;
	for (ll i = 0; i < n; i++) {
		ll n;
		cin >> n;
		if (n < 0) {
			total_negatives++;
			n = -n;
		}
		abs_sum += n;
		smallest_abs_val = min(smallest_abs_val, n);
	}
	if (total_negatives & 1) {
		cout << abs_sum - 2 * smallest_abs_val << endl;
	} else {
		cout << abs_sum << endl;
	}
}
