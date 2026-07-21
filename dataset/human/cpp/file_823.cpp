#include <bits/stdc++.h>
using namespace std;

int main() {
	int r,g,b,n;
	int ans;
	int remainder, nr;
	int green;
	ans = 0;
	cin >> r >> g >> b >> n;
	for (int i = 0; i <= n/r; i++) {
		remainder = n - (r*i);
		green = remainder / g;
		if (remainder == 0) {
			ans++;
		}
		else{
			for (int j = 0; j <= green; j++){
				nr = remainder - j*g;
				if (nr == 0){
					ans++;
				}
				else if (nr > 0 && nr % b == 0){
					ans++;
				}

			}
		}

		
	}
	cout << ans << endl;
}
