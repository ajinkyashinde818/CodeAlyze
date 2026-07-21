#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <math.h>
using namespace std;
typedef long long int ll;

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	ll t; cin >> t;
	vector<ll> v;
	vector<ll> vv;
	v.push_back(1);
	ll a=1;
	for(int i=0;;i++){
		vv.push_back(a);
		a*=3;
		ll k=0;
		for(ll p:vv){
			k+=p*2;
		}
		k+=a;
		if(k<=t){
			v.push_back(k);
		}
		else{
			break;
		}
	}
	ll ans=1e18;
	for(int i=0;i<v.size();i++){
		ll cnt=2*(i+1)-1;
		ll cp=t;
		cp-=v[i];
		for(int j=i;j>=0;j--){
			cnt+=cp/vv[j];
			cp%=vv[j];
		}
		ans=min(ans,cnt);
	}
	vector<ll> f;
	vector<ll> ff;
	f.push_back(0);
	a=1;
	for(int i=0;;i++){
		ff.push_back(a);
		a*=3;
		ll k=0;
		for(ll p:ff){
			k+=p*2;
		}
		k+=a;
		k--;
		if(k<=t){
			f.push_back(k);
		}
		else{
			break;
		}
	}
	for(int i=0;i<f.size();i++){
		ll cnt=2*(i+1)-2;
		ll cp=t;
		cp-=f[i];
		for(int j=i;j>=0;j--){
			cnt+=cp/ff[j];
			cp%=ff[j];
		}
		ans=min(ans,cnt);
	}
	cout << ans << endl;
}
