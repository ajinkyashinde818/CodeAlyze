#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	int n, r;
	cin >> n >> r;
	if (n <= 10) {
		cout << r + (10 - n) * 100 << endl;
	}
	else {
		cout << r << endl;
	}

	return 0;
}
