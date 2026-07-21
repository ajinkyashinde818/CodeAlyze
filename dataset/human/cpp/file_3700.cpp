#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int N;
	cin >> N;

	long long ans = 0;
	int minimum = (1e9),cnt= 0;
	bool zero = false;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		if (tmp < 0) cnt++;
		minimum = min(abs(tmp), minimum);
		if (tmp == 0) zero = true;
		ans += abs(tmp);
	}
	
	if (zero || cnt %2 == 0) {
		cout << ans << endl;
	}
	else {
		cout << ans - 2 * minimum << endl;
	}


	return 0;
}
