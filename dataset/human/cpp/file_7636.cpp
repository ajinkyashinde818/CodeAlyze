#include<bits/stdc++.h>
using namespace std;
typedef long long lld;

int main(){
	lld n;
	cin>>n;
	
	vector<lld > v(n+1);
	vector<lld > pre(n+5,0),post(n+5,0);
	for(lld i=1;i<=n;i++){
		cin>>v[i];
		pre[i]=pre[i-1]+v[i];
	}
	
	for(lld i=n;i>=1;i--){
		post[i]=post[i+1]+v[i];
	}
	post[n+1]=LLONG_MAX;
	lld ans=LLONG_MAX;
	for(lld i=1;i<=n;i++){
		ans=min(ans,abs(pre[i]-post[i+1]));
	}
	cout<<ans;
}
