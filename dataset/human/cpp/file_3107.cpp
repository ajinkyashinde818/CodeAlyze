#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> a;
long long b[100010][2];
bool f[100010][2];

long long func(int x, int t){
	if(f[x][t]) return b[x][t];
	if(x == n-1){
		f[x][t] = true;
		return b[x][t] = (1-2*t) * a[x];
	}
	long long res = -1e18;
	res = (1-2*t) * a[x] + func(x+1, 0);
	res = max(res, (2*t-1) * a[x] + func(x+1, 1));
	f[x][t] = true;
	return b[x][t] = res;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	a.resize(n);
	for(auto &i:a) cin >> i;
	cout << func(0, 0) << "\n";
//	for(int i=0; i<n; ++i)
//		cout << b[i][0] << " " << b[i][1] << "\n";
}
