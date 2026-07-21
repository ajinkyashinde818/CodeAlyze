#include <bits/stdc++.h>
using namespace std;

int m, n;

bool nImage[50][50];
bool mImage[50][50];

int main() {
	cin >> n >> m;
	
	char c;
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
		cin >> c;
		nImage[i][j] = (c == '#');
	}
	for(int i = 0; i < m; i++) for(int j = 0; j < m; j++) {
		cin >> c;
		mImage[i][j] = (c == '#');
	}
	bool ans = false;
	for(int i = 0; i <= n-m; i++) for(int j = 0; j <= n-m; j++) {
		bool valid = true;
		for(int mi = i; mi < i+m; mi++) for(int mj = j; mj < j+m; mj++) {
			valid = (valid && (nImage[mi][mj] == mImage[mi-i][mj-j]));
		}
		ans = (ans || valid);
	}

	cout << (ans? "Yes":"No") << endl;

	return 0;
}
