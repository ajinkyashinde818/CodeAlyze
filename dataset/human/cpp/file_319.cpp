#include"bits/stdc++.h"

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int R, G, B, N;
	cin >> R >> G >> B >> N;

	int cnt = 0;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++){
			int sum = R*i + G*j;
			if (sum <=N && (N-sum)%B == 0) {
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
