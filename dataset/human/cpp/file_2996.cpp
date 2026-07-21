#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+10;
ll a[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;
	ll  mi = 0x3f3f3f3f;
	int co =0;
	ll sum =0;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i] < 0) co++;
		ll cc = abs(a[i]);
		sum += cc;
		mi = min(mi,cc);
	}
	if(co&1)
	cout << sum - mi*2<<endl;
	else 
	cout << sum <<endl;
}
