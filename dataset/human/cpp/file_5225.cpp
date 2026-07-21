#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	int n, r;

	cin >> n >> r;

	if (n < 10) {
		r += 100 * (10 - n);
	}

	cout << r;
	return 0;
}
