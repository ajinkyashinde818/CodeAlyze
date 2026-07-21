#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

int main() {
	int n, r;
	cin >> n >> r;

	int inner_rating = 0;
	if (n >= 10) {
		inner_rating = r;
	} else {
		inner_rating = r + 100 * (10 - n);
	}

	cout << inner_rating << endl;
	return 0;
}
