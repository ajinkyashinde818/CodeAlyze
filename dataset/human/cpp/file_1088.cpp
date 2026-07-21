#include <cstdio>
#include <cmath>

#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <deque>

#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int r, g, b, n;
	int res = 0;
	cin >> r >> g >> b >> n;
	for (int i = 0; i <= n / r; i++) {
		int n2 = n - r * i;
		for (int j = 0; j <= n2 / g; j++) {
			int n3 = n2 - g * j;
			if (n3 % b == 0)
				res++;
		}
	}
	cout << res << endl;


}
