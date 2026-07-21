#include<bits/stdc++.h>

using namespace std;

int main() {
	
	ios_base :: sync_with_stdio(0); cin.tie(NULL);

	int N, R;
	cin >> N >> R;

	if (N>=10) {
		cout << R << '\n';
		return 0;
	}

	cout << R + 100 * (10 - N) << '\n';
	return 0;
}
