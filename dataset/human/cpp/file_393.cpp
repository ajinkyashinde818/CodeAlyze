#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {

	int N, R, G, B;

	cin >> R >> G >> B >> N;

	int count = 0;

	for (int x = 0; x <= N; x++) {
		for (int y = 0; y <= N; y++) {
			int t = N - R * x - G * y;
			if (t >= 0 && t%B == 0) {
				count++;
			}
		}
	}

	cout << count << endl;

	return 0;

}
