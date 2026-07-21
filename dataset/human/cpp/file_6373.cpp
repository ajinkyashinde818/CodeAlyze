#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

ll N;
string S;

int main(){
	cin >> N >> S;
	string lr = "L";
	if(S[0]=='W' || S[2*N-1]=='W') {
		cout << 0 << endl;
		return 0;
	}
	for(int i=1;i<2*N;i++)
	{
		if(S[i-1] == S[i]) {
			if(lr[i-1] == 'L') lr += 'R';
			else lr += 'L';
		} else {
			if(lr[i-1] == 'L') lr += 'L';
			else lr += 'R';
		}
	}
	bool flag = true;
	int ltmp = 0, rtmp = 0;
	for(int i=0;i<lr.size();i++) {
		if(lr[i]=='L') ltmp++;
		else rtmp++;
	}
	if(ltmp != rtmp) {
		cout << 0 << endl;
		return 0;
	}
	//cout << lr << endl;
	ll ans = 1;
	ll l = 0;
	for(int i=0;i<2*N;i++) {
		if(lr[i]=='L') {
			l++;
		} else {
			ans *= l;
			ans %= MOD;
			l--;
		}
	}
	for(int i=N;i>=1;i--) {
		ans *= i;
		ans %= MOD;
	}
	cout << ans << endl;
}
