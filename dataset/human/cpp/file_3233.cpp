#include <bits/stdc++.h>

using namespace std;
inline void FAST_IO(){ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);}

int n;
vector<long long> a(100000);
long long tb[100000][2];
bool v[100000][2];

long long dp(int i, bool flip){
	if(i == n-1) return (flip ? a[i]*(-1) : a[i]);
	
	if(v[i][flip]) return tb[i][flip];
	
	long long change = dp(i+1, true) + (flip ? a[i] : a[i]*(-1));
	long long keep = dp(i+1, false) + (flip ? a[i]*(-1) : a[i]);
	
	v[i][flip] = true;
	return tb[i][flip] = max(change, keep);
}

int main() {
	FAST_IO();
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	
	cout << max(a[0] + dp(1,false),a[0]*(-1)+dp(1,true)) << endl;
	
    return 0;
}
