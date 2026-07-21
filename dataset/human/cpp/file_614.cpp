#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>
#include<stack>
#include<queue>

using namespace std;

typedef pair<int, int> P;

int R, G, B, N;

int main() {
	cin >> R >> G >> B >> N;
	int ans = 0;
	int k;
	for (int i = 0; i <= N / R; i++) {
		for (int j = 0; j <= N / G; j++) {
			k = N - (R * i + G * j);
			if (k >= 0 && k % B == 0) { ans++; }
		}
	}

	cout << ans << endl;
}
