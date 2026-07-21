#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>    
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll n, dp[200008];
string s;
ll MOD = 1e9+7;

int main(){
	cin >> n >> s;
	
	ll ans = 1;
	dp[0] = 0;
	for(ll i = 1; i <= 2*n; i++){
		if(dp[i-1] == 0){
			if(s[i-1] == 'W'){
				cout << 0 << endl;
				return 0;
			}
			else{
				dp[i] = 1;
			}
		}
		else{
			if((s[i-1] == 'W' && dp[i-1]%2 == 1) || (s[i-1] == 'B' && dp[i-1]%2 == 0)){
				dp[i] = dp[i-1]+1;
			}
			else{
				ans *= dp[i-1];
				ans %= MOD;
				dp[i] = dp[i-1]-1;
			}
		}
	}
	
	if(dp[2*n] > 0){cout << 0 << endl;}
	else{
		for(ll i = 1; i <= n; i++){
			ans *= i;
			ans %= MOD;
		}
		cout << ans << endl;
	}
	return 0;
}
