#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

int N, R;

int main(void) {

	cin >> N >> R;
	int ans = R;

	if (N <= 9) { ans += 100 * (10 - N); }

	cout << ans << endl;
	return 0;
}
