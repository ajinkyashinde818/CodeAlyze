#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> P;

int main() {

	int n,r;
	cin >> n >> r;
	int out;
	if (n <= 10) {
		out = r + 100 * (10 - n);
	} else {
		out = r;
	}
	cout << out << endl;
	return 0;
}
