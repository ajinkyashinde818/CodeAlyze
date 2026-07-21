#include <bits/stdc++.h>
using namespace std;

int main(void){
	int r, g, b, n;
	long long ans = 0LL;
	cin >> r >> g >> b >> n;
	for(int i = 0; i <= n/r; ++i){
		for(int j = 0; j <= n/g; ++j){
			if( (n-i*r-j*g) % b == 0){
				if((n-i*r-j*g) / b >= 0){
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
}
