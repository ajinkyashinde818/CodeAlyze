#include <bits/stdc++.h>
using namespace std;

int r, g, b, n, ans;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> r >> g >> b >> n;
	for(int i=0; i<=n/r; ++i)
		for(int j=0; j<=n/g; ++j){
			int t = n - i*r - j*g;
			if(t >= 0 && t % b == 0) ++ans;
		}
	cout << ans << "\n";
}
