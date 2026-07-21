#include <bits/stdc++.h>
const long long MOD = 1e9+7;
using namespace std;


int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N,R;
	cin >> N >> R;
	int ans = 0;
	int sum = 0;

	if (N<10) {
		cout << 100*(10-N)+R << endl;	
	} else if (N>=10) {
		cout << R << endl;
	}
	return 0;
}
