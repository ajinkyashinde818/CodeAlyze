#include <iostream>
#include <string.h>
#include <vector>
#include <deque>
#include <bitset>
#include <string>
#include <limits.h>
#include <stdint.h>
#include <algorithm>
#include <tuple>
#include <iomanip>
#include <set>
#include <assert.h>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc >= 2) {
		FILE* fp = freopen(argv[1], "r", stdin);
	}

	int N;
	cin >> N;
	vector<int> v;
	int64_t sum = 0;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
		sum += a;
	}
	int64_t tmp = 0;
	int64_t ret = INT64_MAX;
	for (int i = 0; i < N - 1; i++) {
		tmp += v[i];
		int64_t x = abs(sum - tmp * 2);
		if (x < ret) ret = x;
	}
	cout << ret;
	
	return 0;
}
