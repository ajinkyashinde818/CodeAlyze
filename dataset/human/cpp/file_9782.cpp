#include <iostream>
#include <string>

using namespace std;
long long mod = 1000000007,a[30] = {},ans = 1;
int main(){
	int i,n;
	string s;
	cin >> n >> s;
	for(i=0;i<n;i++){
		a[s[i] - 'a']++;
	}
	for(i=0;i<26;i++){
		(ans *= (a[i] + 1)) %= mod;
	}
	cout << ans - 1 << endl;
}
