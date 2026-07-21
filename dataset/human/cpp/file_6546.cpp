#include <iostream>
#include <cstdio>
using namespace std;

long long n, k, cnt=1, ans=1, M=1e9+7;
string s;
int main() {
	int i;
	cin >> n >> s;
	if(s[0]=='W') {puts("0"); return 0;}
	for(i=1; i<2*n; i++) {
		if(s[i] == s[i-1]) k = 1 - k;
		if(k==0) cnt++;
		else ans = ans * cnt % M, cnt--;
	}
	if(cnt!=0) {puts("0"); return 0;}
	for(i=2; i<=n; i++) ans = ans * i % M;
	cout << ans;
	return 0;
}
