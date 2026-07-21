#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int co = 0, N = 0;
	vector<int> c;
	int count = 0;
	for (int i = 0; i < 3; i++) {
		cin >> co;
		c.emplace_back(co);
	}
	sort(c.begin(), c.end());
	cin >> N;
	
	for (int i = 0; i*c[2] <= N; i++) {
		for (int j = 0; j*c[1] + i*c[2] <= N; j++) {
			if ((N - (j*c[1] + i*c[2])) % c[0] == 0) {
				count++;
			}
		}
	}
	cout << count;

	return 0;
}
