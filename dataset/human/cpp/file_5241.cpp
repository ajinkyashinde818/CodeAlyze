#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <string>
#include <queue>
#include <deque>
#include <vector>
#include <map>
#include <math.h>
#include <limits.h>

using namespace std;

int main() {
	int n, r;
	cin >> n >> r;
	if (n < 10) {
		cout << r + (100 * (10 - n));
	}
	else cout << r << endl;
	return 0;
}
