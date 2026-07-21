#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;
	int r = 0, p = 1e9 + 7;
	long a = 1;
	for (int i = 0; i < n; i++)
		(a *= i + 1) %= p;
	for (int i = 0; i < n + n; i++) {
		if (s[i] == 'B'^i & 1)
			r++;
		else (a *= r--) %= p;
	}
if(r) a=0;
	cout << a << endl;
	return 0;
}
