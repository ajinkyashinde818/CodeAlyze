#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>

using namespace std;


int main() {
	int R, G, B, N;
	cin >> R >> G >> B >> N;

	int count = 0;
	
	for (int r = 0; r <= N / R; r++) {
		int m = N - r * R;
		for (int g = 0; g <= m / G; g++) {
			int l = m - g * G;
			if (l % B == 0) {
				count++;
			}
		}
	}

	cout << count << endl;

	return 0;
}
