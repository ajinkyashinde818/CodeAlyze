#include <iostream>

using namespace std;

int main() {
	int R, G, B , N;
	int count = 0;

	cin >> R >> G >> B >> N;

	for (int r = 0; r <= N; r += R) {
		for (int g = 0; g + r <= N; g += G) {
			int b = N - r - g;
			if (b < 0) {
				continue;
			}
			if (b % B != 0) {
				continue;
			}
			count ++;
		}
	}
	cout << count << endl;

	return 0;
}
