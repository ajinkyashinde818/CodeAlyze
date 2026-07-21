#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int mod = 1e9+7; 
char s[N];  
int d[N], r[N]; 
int main(){
	int n, ans; 
	scanf("%d", &n);
	scanf("\n%s", s+1); 
	for(int i=1; i<=n*2; ++i){
		d[i] = d[i-1]; 
		if(s[i] == s[i-1]) d[i] ^= 1; 
	}
	for(int i=n*2; i>=1; --i){
		if(d[i] == 1) r[i] = r[i+1]+1; 
		else r[i] = r[i+1]-1; 
	}
	ans = 1; 
	for(int i=1; i<=n*2; ++i)
		if(r[i] < 0){
			ans = 0; 
			break; 
		}
	if(r[1] != 0 || s[1] == 'W') ans = 0; 
	for(int i=1; i<=n*2; ++i)
		if(!d[i]) ans = 1ll*ans*(r[i]+1)%mod; 
	for(int i=1; i<=n; ++i) ans = 1ll*ans*i%mod; 
	printf("%d\n", ans); 
	return 0; 
}
