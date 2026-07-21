#include <iostream>
#include <vector>
#include <set>
#include <array>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include <numeric>
#include <random>
#include <iomanip>
#include <chrono>

using namespace std;

int main() {

	int n, r;
	cin >> n >> r;

	cout << ((n >= 10) ? r : r + (10 - n) * 100) << endl;

	return 0;
}
