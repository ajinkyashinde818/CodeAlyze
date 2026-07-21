#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll n;
	cin>>n;
	ll a[n],v[n];
	for(ll i=0;i<n;i++){
		cin>>a[i];
		v[i]=0;
	}
	v[0]=a[0];
	for(ll i=1;i<n;i++){
		v[i]+=a[i]+v[i-1];
	//	cout<<"i:"<<i<<" v:"<<v[i]<<endl;
	}
	ll res=1000000000000000001;
	for(ll i=0;i<n-1;i++){
		res = min(res,abs((v[n-1]-v[i])-v[i]));
	}
	cout<<res<<endl;
}
