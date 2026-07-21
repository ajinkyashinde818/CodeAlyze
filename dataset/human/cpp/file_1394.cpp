#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>
#include <bitset>
#include <functional>
#include <numeric>
#include <ctime>
#include <cassert>
#include <cstring>
#include <fstream>

using namespace std;

int main() {
	int r, g, b, n;
	cin >> r >> g >> b >> n;
	int cnt = 0;
	for (int i = 0; i*r <= n; i++) {
		for (int j = 0; i*r + j * g <= n; j++) {
			int rest = n - i * r - j * g;
			if (rest % b == 0)
				cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
