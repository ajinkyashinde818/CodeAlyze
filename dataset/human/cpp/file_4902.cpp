#include <bits/stdc++.h>
using namespace std;
using Int = int_fast64_t;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, r; cin >> n >> r;
	if(n >= 10) cout << r << "\n";
	else cout << r + 100 * (10 - n) << "\n";
}
