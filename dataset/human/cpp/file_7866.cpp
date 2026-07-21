#include<bits/stdc++.h>
using namespace std;
using ll = long long;



int main(){
	ll n, sum = 0;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	
	ll s = 0, ans = abs(sum-2*a[0]);
	for(int i = 0; i < n-1; i++)
	{
		s += a[i];
		ans = min(ans, abs(sum - 2*s));
	}
	
	cout << ans << endl;

	return 0;
}
