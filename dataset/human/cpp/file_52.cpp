#include <bits/stdc++.h>
using namespace std;

int main() {
	int R, G, B, N;
	cin >> R >> G >> B >> N;
	int count = 0;
	for (int r = 0; r < N / R + 1; r++) {
		for (int g = 0; g < (N - r * R) / G + 1; g++) {
			int ord = N - r * R - g * G;
			if(ord % B == 0) {
					count++;
			}
		}
	}
	cout << count << endl;
}
