#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
	int n, r;
	cin >> n >> r;
	if (n < 10) r += 100 * (10 - n);
	cout << r << endl;
}
