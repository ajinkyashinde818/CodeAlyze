#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>	

using namespace std;

int main() {
	int r, g, b, N;
	cin >> r >> g >> b >> N;

	int ans = 0;

	for (int i = 0; (N - (i * g)) >= 0; ++i) {
		for (int j = 0; (N - (i * g + j * b)) >= 0; ++j) {
			if ((N - (i * g + j * b)) % r == 0) {
				++ans;
			}
		}
	}

	cout << ans << endl;

	return 0;
}
