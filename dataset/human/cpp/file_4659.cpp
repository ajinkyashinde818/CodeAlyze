/**
 * @author      : omgursocute
 * @created     : 23/02/2020
 * @task        : A
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main() {
	// freopen("A.inp", "r", stdin);
	// freopen("A.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, r;
	cin >> n >> r;
	if(n >= 10) cout << r;
	else cout << r + 100*(10-n);

	return 0;
}
