#include "bits/stdc++.h"
using namespace std;

int main() {
	long long R, G, B, N, count = 0;
	cin >> R >> G >> B >> N;
	for (int i = 0; i <= N / R; i++) {
		int n = N - R * i;
		for (int j = 0; j <= n / G; j++) {
			if (n - j * G >= 0 && (n - j * G) % B == 0) count++;
		}
	}
	cout << count;
}
