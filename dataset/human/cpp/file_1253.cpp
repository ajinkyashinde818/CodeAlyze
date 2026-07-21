#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int r, g, b, n;
	long long count = 0;

	cin >> r >> g >> b >> n;

	for (int i = 0; i <= n / r; i++) {
		for (int j = 0; j <= (n - r*i) / g; j++) {
			if ((n - r*i - g*j) % b == 0) {
				count++;
			}
		}
	}

	cout << count << endl;
}
