#include <bits/stdc++.h>
using namespace std;
/**
  BBBB
  12 34
  BWWB
  14
  23
  **/
const int mod = 1'000'000'007;
int mul(long long a, long long b){
	return a * b % mod;
}
int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int open = 1;
	int res = 1;
	if(s[0] != 'B'){
		cout << 0 << endl;
		return 0;
	}
	for(int i = 1; i < 2 * n; i++){
		int sign = s[i] == 'B' ? 1 : 0;
		if((open % 2) == sign) {
			res = mul(res, open);
			open--;
		} else {
			open++;
		}
		if(open < 0)
			res = 0;	
	}
	if(open != 0)
		res = 0;
	for(int i = 1; i <= n; i++)
		res = mul(res, i);
	cout << res << endl;
	return 0;
}
