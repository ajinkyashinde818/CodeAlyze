#include <bits/stdc++.h>
using namespace std;
int q; unsigned x;
int main() {
	cin >> q;
	while(q--) {
		scanf("%x", &x);
		int f = 0;
		if(x >= 2147483648) x -= 2147483648, f = 1;
		long long r1 = x / 128, r2 = x % 128;
		if(f) cout << "-";
		cout << r1 << '.';
		int c = 0;
		while(r2 % 128 != 0) r2 *= 10, c++;
		string s = to_string(r2 / 128);
		while(s.size() < c) s = "0" + s;
		cout << s << endl;
	}
}
