#include <iostream>
#include <cmath>
#include <valarray>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
	ll n, r;
	cin >> n >> r;
	ll rate = r;
	if (n <= 10) {
		rate = r+  100 * (10 - n);
	}
	cout << rate << endl;
	system("PAUSE");
}
