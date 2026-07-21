#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <functional>
#include <iomanip>
#include <bitset>
#include <numeric>
#include <queue>
#include <map>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
const long long mod = 1000000007;
typedef long long ll;
typedef pair<int, int> P;
const vector<int> di = {-1, 0, 1, 0};
const vector<int> dj = { 0, 1, 0, -1 };

int main() {

	int n, r;
	cin >> n >> r;

	if (n >= 10) {
		cout << r << endl;
	}
	else {
		cout << r + 100 * (10 - n) << endl;
	}

	return 0;
}
