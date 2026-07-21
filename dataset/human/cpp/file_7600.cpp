#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int N=1e6+10;
ll a[N],ans=1000000000000000000;

int main(){
	ll i,j,k,n,x=0,sum=0;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	for(i=1;i<n;i++){
		x+=a[i];
		ans=min(ans,abs(2*x-sum));
	}
	cout<<ans;
	return 0;
}
