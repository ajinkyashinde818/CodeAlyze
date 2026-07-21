#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,i;
	long long a[200005],x=0,s=0,ans=1e18;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
		s+=a[i];
	}
	for(i=0;i<n-1;i++){
		x+=a[i];
		ans=min(ans,abs(2*x-s));
	}
	cout<<ans;
	return 0;
}
