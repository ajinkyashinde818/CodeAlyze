#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9+7;
int n;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	ll pre = 0, ans = 1;
	for(int i=1; i<=2*n; i++){
		char c; cin >> c;
		int op = (c == 'B');
		if(op == (pre&1)){		// ]
			ans = ans * pre % MOD; 
			pre--;
		}else{		// [
			pre++;
		}
	}

	if(pre != 0){
		cout << 0;
	}else{
		for(int i=1; i<=n; i++)
			ans = ans * i % MOD;
		cout << ans;
	}

	return 0;
}
