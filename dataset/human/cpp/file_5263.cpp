#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main () {
	int n, r;
	cin >> n >> r;
	if(n >= 10) {
		cout << r << "\n";
	}else {
		int diff = 10 - n;
		cout << (r + 100 * diff) << "\n";
	}
	return 0;
}
