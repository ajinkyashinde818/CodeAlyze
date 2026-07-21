#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

#define INF 2140000000
#define MOD 1000000007

int main() {
	int n;

	cin >> n;

	long long num, sum = 0, minn = INF, cnt = 0;

	for (int i = 0; i < n; ++i) {
		cin >> num;

		if (num < 0) {
			cnt++;
		}

		sum += abs(num);
		minn = min(minn, abs(num));
	}

	if (cnt % 2 == 0) {
		cout << sum << endl;
	}
	else {
		cout << sum - 2 * minn << endl;
	}

	return 0;
}
