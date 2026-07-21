#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e5+10;
ll n,c,x[maxn],v[maxn],a[maxn],b[maxn],ans;

int main(){
	cin>>n>>c;
	for(int i=1;i<=n;++i)
		cin>>x[i]>>v[i];
	for(int i=1;i<=n;++i)
		a[i]=a[i-1]+v[i];
	for(int i=n;i;--i)
		b[i]=b[i+1]+v[i];
	for(int i=1;i<=n;++i){
		ans=max(ans,a[i]-x[i]);
		ans=max(ans,b[i]-(c-x[i]));
	}
	ll tmp1=-1e18,tmp2=-1e18;
	for(int i=n-1;i;--i){
		tmp1=max(tmp1,b[i+1]-(c-x[i+1]));
		tmp2=max(tmp2,b[i+1]-2*(c-x[i+1]));
		ans=max(ans,a[i]+tmp1-2*x[i]);
		ans=max(ans,a[i]+tmp2-x[i]);
	}
	cout<<ans<<endl;
	return 0;
}
