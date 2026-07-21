#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>
#include <random>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <climits>
#include <bitset>

#define FOR_LT(i, beg, end) for (int i = beg; i < end; i++)
#define FOR_LE(i, beg, end) for (int i = beg; i <= end; i++)
#define FOR_DW(i, beg, end) for (int i = beg; end <= i; i--)

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int r, g, b, n; cin >> r >> g >> b >> n;

	int64_t cases = 0;
	int r_max = n / r;
	FOR_LE(i, 0, r_max) {
		int cur = n - r * i;

		int j = 0;
		while (j * g <= cur) {
			if ((cur - j * g) % b == 0) cases++;
			j++;
		}
	}

	cout << cases << endl;

	return 0;
}
