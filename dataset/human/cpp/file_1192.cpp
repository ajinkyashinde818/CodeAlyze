#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
int main() {
	int r, g, b, n;
	cin >> r >> g >> b >> n;
	int co = 0;
	for (int i = 0; i <= 3000; i++) {
		if (r * i > n) {
			continue;
		}
		for (int j = 0; j <= 3000; j++) {
			if (r * i + g * j <= n) {
				if ((n - r * i - g * j) % b == 0) {
					co++;
				}
			}
		}
	}
	cout << co << endl;
	return 0;
}
