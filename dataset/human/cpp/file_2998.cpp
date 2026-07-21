#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n; cin>>n;
	vector<ll> a(n);
	int neg = 0;
	for(int i = 0; i < n; i++){
		cin>>a[i];
		if(a[i] < 0)neg++;
		a[i] = abs(a[i]);
	}
	sort(a.begin(), a.end());
	ll sum = accumulate(a.begin(), a.end(), 0LL);
	if(neg&1)cout<<sum - 2*a[0]<<'\n';
	else cout<<sum<<'\n';

	return 0;
}
