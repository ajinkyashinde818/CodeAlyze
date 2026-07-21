#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, r;
	cin >> n >> r;
	int ans;
	if(n >= 10) {
		ans = r;
	}else {
		ans = r + (10 - n) * 100;
	}
	cout << ans << endl; 
}
