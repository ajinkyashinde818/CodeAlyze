#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF=1e18,MOD=1e9+7;
int main(){
	ll mini=INF,ans=0,n,cnt=0;
	cin>>n;
	vector<ll>a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]<0)cnt++;
		a[i]=abs(a[i]);
		mini=min(mini,a[i]);
		ans+=a[i];
	}
	if(cnt%2==1)ans-=mini*2;
	cout<<ans<<endl;

}
