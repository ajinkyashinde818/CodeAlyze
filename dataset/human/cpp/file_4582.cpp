#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
	int n, r;
	cin >> n >> r;

	if (n < 10) {
		cout << r + 100*(10-n) << endl;
	} else {
		cout << r << endl;
	}
	return 0;
}
