#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a[100050]={0},b[100050]={0};
ll dp1[100050]={0},dp2[100050]={0},ma1[100050]={0},ma2[100050]={0};
int main(){
	int n,i;
	ll c,sum=0,ans=0,t;
	cin>>n>>c;
	for(i=1;i<=n;i++){
		scanf("%lld %lld",&b[i],&a[i]);
	}
	dp1[0]=0;
	dp2[0]=-c;
	for(i=1;i<=n;i++){
		dp1[i]=dp1[i-1]+a[i]-b[i]+b[i-1];
		ma1[i]=max(ma1[i-1],dp1[i]);
		ans=max(ans,dp1[i]);
		dp2[i]=dp2[i-1]+a[n-i+1]+b[n-i+1]-b[n-i+2];
		ans=max(ans,dp2[i]);
		ma2[i]=max(ma2[i-1],dp2[i]);
	}
	for(i=1;i<n;i++){
		t=dp1[i]-b[i];
		if(t>0) {
			sum=t+ma2[n-i];
			ans=max(sum,ans);
		}
	}
	for(i=1;i<n;i++){
		t=dp2[i]-c+b[n-i+1];
		if(t>0) {
			sum=t+ma1[n-i];
			ans=max(sum,ans);
		}
	}
	cout<<ans<<endl;
}
