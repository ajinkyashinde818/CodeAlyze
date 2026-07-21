#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll n, r;
	cin >> n >> r;
	if(n >= 10) {
		cout << r;
	} else {
		cout << r + (100 * (10 - n));
	}
}
