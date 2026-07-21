#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <bitset>
#include <numeric>
#include <ccomplex>
#include <cassert>
#include <random>
using namespace std;
using ll = long long;


int main() {
	int n, r; cin >> n >> r;
	if (n >= 10) cout << r << endl;
	else cout << r + 100 * (10 - n) << endl;
	return 0;
}
