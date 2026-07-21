/*input
2
10 -10
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;
	long long a[n], b[n], c[n];
	for(int i = 0; i < n; i ++) cin >> a[i];
	b[0] = a[0];
	for(int i = 1; i < n; i ++) b[i] = a[i] + b[i-1];
	c[n-1] = a[n-1];	
	for(int i = n-2; i >= 0; i --) c[i] = c[i+1] + a[i]; 
	//for(int i = 0; i < n; i ++) cout << a[i] << " " << b[i] << " " << c[i] << endl;
	long long ans = LONG_LONG_MAX;
	for(int i = 0; i < n - 1; i ++) ans = min(ans, abs(b[i] - c[i+1]));
	cout << ans << endl;
	return 0;
}
