#include <bits/stdc++.h>

using namespace std;

int a[222];
int main() {
	int n, p = 1e9 + 7;
	string s;
	cin >> n >> s;
	for (auto c : s)
		a[c]++;
	long r = 1;
	for (int i = 'a'; i <= 'z'; i++)
		(r *= a[i] + 1) %= p;
	cout << (r + p - 1) % p << endl;
	return 0;
}
