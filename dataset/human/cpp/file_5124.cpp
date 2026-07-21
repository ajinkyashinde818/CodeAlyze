#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	int N, R;
	cin >> N >> R;
	if(N >= 10)
		cout << R << "\n";
	else
		cout << R + 100 * (10 - N) << "\n";
	return 0;
}
