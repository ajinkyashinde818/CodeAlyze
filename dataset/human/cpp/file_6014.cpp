#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long int ll;

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	ll c; cin >> c;
	vector<ll> x(n);
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin >> x[i] >> v[i];
	}
	ll ans=0;
	for(int t=0;t<2;t++){
		ll sum=0;
		for(int i=0;i<n;i++){
			sum+=v[i];
		}
		ll mx=0;
		ll cnt=0;
		for(int i=n-1;i>=-1;i--){
			ll now=sum-(i>=0?x[i]:0);
			ans=max(ans,now+mx);
			if(i>=0){
				cnt+=v[i];
				mx=max(mx,cnt-2*(c-x[i]));
				sum-=v[i];
			}
		}
		for(int i=0;i<n;i++){
			x[i]=c-x[i];
		}
		reverse(x.begin(),x.end());
		reverse(v.begin(),v.end());
	}
	cout << ans << endl;
}
