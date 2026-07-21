#include <iostream>
#include <cstdio>
using namespace std;

int a, b, c, n, ans;

int main() {
	int i, j, t;
	cin >> a >> b >> c >> n;
	for(i=0; i<=3000; i++) for(j=0; j<=3000; j++) {
		t = n - a*i - b*j;
		if(t<0) break;
		if(t % c == 0) ans++;
	}
	cout << ans;
	return 0;
}
