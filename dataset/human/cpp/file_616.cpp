#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int main() {

	int R, G, B, N;

	cin >> R >> G >> B >> N;

	int r=0, g=0, b=0;

	int count = 0;

	for (r = 0; true; r++) {
		for (g = 0; true; g++) {
			if ((N - R * r - G * g) % B == 0 && R * r + G * g <= N)
				count++;

			if (R * r + G * g >= N) {
				g = 0;
				break;
			}
		}

		if (R * r + G * g >= N) {
		break;
		}
	}
	cout << count << endl;

	return 0;
}
