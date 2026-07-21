#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> data(N);
	long long int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> data[i];
		sum += data[i];
	}

	bool init = false;
	long long int min_el = 0;
	long long int cur = 0;

	for (int i = 0; i < N - 1; i++) {
		cur += data[i];
		long long int temp = abs(cur - (sum - cur));
		if (init) {
			min_el = min(min_el, temp);
		} else {
			min_el = temp;
			init = true;
		}

	}

	cout << min_el << endl;

	return 0;
}
