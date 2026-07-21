#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 200100;

ll x[maxn];
ll v[maxn];
ll f1[maxn];
ll s1[maxn];
ll f2[maxn];
ll s2[maxn];
ll maxf1[maxn];
ll maxf2[maxn];

int main(){
	int n;
	ll c;
	scanf("%d%lld",&n,&c);
	ll sumv=0;
	for(int i=0;i<n;i++){
		scanf("%lld%lld",&x[i],&v[i]);
		sumv+=v[i];
	}
	ll ans=sumv-c+max(x[0],c-x[n-1]);
	ll ans1=0;
	ll maxs=0;
	s1[0]=0;
	for(int i=0;i<n;i++){
		s1[i+1]=s1[i]+v[i];
		f1[i+1]=s1[i+1]-2*x[i];
		maxf1[i+1]=max(maxf1[i],f1[i+1]);
	}
	s2[n]=0;
	ll ans2=0;
	for(int i=n-1;i>=0;i--){
		s2[i]=s2[i+1]+v[i];
		f2[i]=s2[i]-2*(c-x[i]);
		maxf2[i]=max(maxf2[i+1],f2[i]);
	}
	for(int i=0;i<n;i++){
		ans1=max(ans1,maxf2[i+1]+s1[i+1]-x[i]);
	}
	for(int i=n-1;i>=0;i--){
		ans2=max(ans2,maxf1[i]+s2[i]-(c-x[i]));
	}
	ans=max(ans,max(ans1,ans2));
	printf("%lld\n",ans);
	return 0;
}
