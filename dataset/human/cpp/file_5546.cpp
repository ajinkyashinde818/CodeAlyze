#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <stdlib.h>

typedef long double ld;
typedef long long ll;

using namespace std;

int main() {
	int n, r;
	cin >> n >> r;
	if (n >= 10) {
		cout << r << endl;
	} else {
		cout << r + 100 * (10 - n) << endl;
	}

	return 0;
}
