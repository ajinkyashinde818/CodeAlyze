#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint MOD = 1e9+7;

signed main(){
	lint N; cin >> N;
	vector<char> s(2 * N);
	for(int i = 0; i < s.size(); i++) cin >> s[i];
	vector<char> t(s.size());
	t[0] = 'L';
	int l = 1, r = 0;
	for(int i = 1; i < s.size(); i++){
		if(s[i] == s[i - 1]){
			if(t[i - 1] == 'L') t[i] = 'R', r++;
			else t[i] = 'L', l++;
		}
		else{
			if(t[i - 1] == 'L') t[i] = 'L', l++;
			else t[i] = 'R', r++;
		}
	}	
	if(s[0] == 'W' || s[s.size() - 1] == 'W' || l != r){
		cout << 0 << endl;
		return 0;
	}
	
	lint ans = 1, num = 0;
	vector<lint> counter(s.size(), 0);
	for(int i = 1; i < counter.size(); i++) counter[i] = counter[i - 1] + (t[i] == 'R');
	for(lint i = 2; i <= N; i++) ans *= i, ans %= MOD;
	for(int i = t.size() - 1; i >= 0; i--){
		if(t[i] == 'L'){
			ans *= (r - counter[i] - num);
			ans %= MOD;
			num++;
		}
	}
	cout << ans << endl;
}
