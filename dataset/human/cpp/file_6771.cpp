#include<bits/stdc++.h>
using namespace std;
int a[212345];
int b[212345];
int c[212345];
//int ha[212345];
//int hb[212345];
vector<int>t;
int n;
int f(int x) {
	for (int i = 0; i < n; ++i) {
		if (a[i] != c[x] && a[x] != c[i]) {
			swap(c[i], c[x]);
			return 1;
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)cin >> a[i];
	for (int i = 0; i < n; ++i)cin >> b[i];
	/*for (int i = 0; i < n; ++i)++ha[a[i]];
	for (int i = 0; i < n; ++i)++hb[b[i]];*/
	int cnt1 = 0, cnt2 = n - 1;
	for (int i = 0; i < n; ++i) {
		if (a[i] != b[cnt1]) {
			c[i] = b[cnt1++];
		}
		else if (a[i] != b[cnt2]) {
			c[i] = b[cnt2--];
		}
		else {
			c[i] = b[cnt1++];
			t.push_back(i);
		}
	}
	for (auto& x : t) {
		int y = f(x);
		if (y == -1) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	for (int i = 0; i < n; ++i)cout << c[i] << " ";
	cout << endl;
	return 0;
}
