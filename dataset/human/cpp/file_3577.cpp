#include <bits/stdc++.h>
using namespace std;
const int maxn = 123456;
long long f[2][maxn];
int main(){
	f[0][0] = 0;
	f[1][0] = -(1ll<<60);
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		f[0][i + 1] = max(f[0][i] + x, f[1][i] - x);
		f[1][i + 1] = max(f[0][i] - x, f[1][i] + x);
	}
	cout << f[0][n] << endl;
	return 0;
}
