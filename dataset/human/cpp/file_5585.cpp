#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int N, R;
	cin >> N >> R;
	int ans;
	if (N >= 10) ans = R;
	else ans = R + (100 * (10 - N));
	cout << ans << endl;
	return 0;
}
