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
using namespace std;
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
