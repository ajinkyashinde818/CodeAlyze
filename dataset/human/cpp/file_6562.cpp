#include <bits/stdc++.h>

using namespace std;
long long mod = 1000000007;
int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	n *= 2;
	string s;
	cin >> s;
	
	int cnt = 0;
	for(int i = 0;i < n;i++){
		if(s[i] == 'B') cnt++;
		else cnt--;
	}
	if(cnt % 2 != 0){
		cout << "0";
		return 0;
	}
	
	long long pre = 0;
	bool start[n];
	for(int i = 0;i < n;i++){
		if(s[i] == 'B'){
			if(pre % 2 == 0){
				start[i] = true;
				pre++;
			}
			else{
				start[i] = false;
				pre--;
			}
		}
		else{
			if(pre % 2 == 0){
				start[i] = false;
				pre--;
			}
			else{
				start[i] = true;
				pre++;
			}
		}
	}
	
	cnt = 0;
	for(int i = 0;i < n;i++){
		if(start[i]) cnt++;
		else cnt--;
		if(cnt < 0){
			cout << "0";
			return 0;
		}
	}
	if(cnt != 0){
		cout << "0";
		return 0;
	}
	
	long long ans = 1;
	pre = 0;
	for(int i = 0;i < n;i++){
		if(start[i]) pre++;
		else{
			ans *= pre;
			pre--;
			ans %= mod;
		}
	}	
	
	for(long long x  = 1;x <= n/2;x++){
		ans *= x;
		ans %= mod;
	}
	cout << ans;
}
