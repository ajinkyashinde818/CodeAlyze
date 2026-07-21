#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int R, G, B, N;
	cin >> R >> G >> B >> N;
	int ans = 0;

	for (int i = 0; i < 3001; i++) {
		for (int j = 0; j < 3001; j++) {
			int temp;
			temp = N - (R * i + G * j);
			if (temp < 0) {
				continue;
			}
			if (temp%B == 0) {
				ans++;
			}
		}
	}

	cout << ans << endl;

	return 0;
}
