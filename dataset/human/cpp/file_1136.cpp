#include <bits/stdc++.h>   
using namespace std;   

int main()  
{  
	int ans = 0;
	int r, g, b, n; cin >> r >> g >> b >> n;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			int t = i*r + j*g;
			if (n >= t && (n-t) % b == 0)
				ans++;
		}
	}
	cout << ans << endl;
	return 0;   
}
