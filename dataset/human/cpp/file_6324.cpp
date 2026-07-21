#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[200009], m = 1e9 + 7, dir[200009];

int main() {
	ll n;
	cin>>n;
	string s;
	cin>>s;
	
	f[1] = 1;
	for(ll i = 2; i <= n; i++){
		f[i] = f[i-1]*i;
		f[i] %= m;
	}
	
	dir[0] = 0;
	ll x = 1, y = 0;
	for(ll i = 1; i < s.size(); i++){
		if(s[i] == s[i-1]){
			dir[i] = dir[i-1]^1;
		}
		else{
			dir[i] = dir[i-1];
		}
		if(dir[i] == 0){
			x++;
		}
		else{
			y++;
		}
	}
	ll pos = 1;
	
	if(s[0] == s[s.size()-1] and s[0] == 'B' and dir[s.size() - 1] == 1){
		
	}
	else{
		pos = 0;
	}
	if(x != y){
		pos = 0;
	}
	ll op = 1, cl = 0, tot = 1;
	for(ll i = 1; i < s.size(); i++){
		if(dir[i] == 1){
			if(op <= 0){
				pos = 0;
			}
			tot *= op;
			op--;
			tot %= m;
		}
		else{
			op++;
		}
	}
	tot*= f[n];
	tot %= m;
	tot *= pos;
	cout<<tot;
}
