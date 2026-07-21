#include <bits/stdc++.h>
using namespace std;
int main() {
	int r,g,b,n;
	cin>>r>>g>>b>>n;
	int cnt=0;
	for (int i = 0; i <= n/r; i++) {
		for (int j = 0; j <= n/g; j++) {
			if (r*i + g*j <= n && (n - (r*i + g*j)) % b == 0) {
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}
