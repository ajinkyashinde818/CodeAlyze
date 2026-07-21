#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<long long> card;
	for (int i = 0; i < N; i++) {
		long long t;
		cin >> t;
		if (i != 0) {
			card.push_back(t + card[i - 1]);
		}
		else {
			card.push_back(t);
		}
	}
	long long total = card[N - 1];

	int count = 0;
	long long min = numeric_limits<long long>::max() - 1;
	for (int i = 0; i < N - 1; i++) {
		long long x, y, z;
		x = card[i];
		y = total - card[i];
		z = abs(x - y);
		if (min > z) {
			min = z;
		}
	}
	cout << min << endl;
	return 0;
}
