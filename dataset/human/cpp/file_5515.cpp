#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <utility>
#include <numeric>
#include <queue>
#include <stack>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9) + 7;

int main(void) {
	int n, r;
	cin >> n >> r;
	
	if( n < 10 ) {
		cout << r + 100 * (10 - n) << endl;
	} else {
		cout << r << endl;
	}
	
	return 0;
}
