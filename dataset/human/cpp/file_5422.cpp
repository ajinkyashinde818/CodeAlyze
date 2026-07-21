#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>
#include <iostream>

using namespace std;
int main() {
	int n, r;
	int ans;
	cin >>n >> r;

	if (n <= 10) {
		cout << r + 100 * (10 - n);
	}
	else {
		cout << r;
	}

	return 0;
}
