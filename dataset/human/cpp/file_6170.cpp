#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<string>
#include<stack>
#include<algorithm>
#include<memory.h>
#include<set>
#include<map>
#include<cmath>
#include<time.h>
#include<iomanip>
#include<time.h>
using namespace std;
typedef long long ll;
#define se second
#define fi first
#define pb push_back
const int N = 1e6, M = 1e9 + 7;
const double PI = acos(-1);
int n;
vector<ll>v;
ll cs[N],C;
ll back[N],seg1[4*N],seg2[4*N],front[N];
int range[N];
void build(int p,int s,int e){
	if(s==e){
		seg1[p]=back[s];
		seg2[p]=front[s];
		return;
	}
	build(2*p,s,(s+e)/2);
	build(2*p+1,(s+e)/2+1,e);
	seg1[p]=max(seg1[2*p],seg1[2*p+1]);
	seg2[p]=max(seg2[2*p],seg2[2*p+1]);
}
int l,r;
ll get1(int p,int s,int e){
	if( s>r || e<l)return 0;
	if(s>=l && e<=r)return seg1[p];
	return max(get1(2*p,s,(s+e)/2),get1(2*p+1,(s+e)/2+1,e));
}
ll get2(int p,int s,int e){
	if( s>r || e<l)return 0;
	if(s>=l && e<=r)return seg2[p];
	return max(get2(2*p,s,(s+e)/2),get2(2*p+1,(s+e)/2+1,e));
}
int main() {
	scanf("%d%lld",&n,&C);
	for(int i=0;i<n;i++){
		ll x;
		scanf("%lld%d",&x,&cs[i]);
		v.pb(x);
		
	}
	ll sm=0;
	int idx=0;
	for(int i=n-1;i>=0;i--){
		sm+=cs[i];
		ll tmp=sm-(C-v[i]);
		back[idx]=tmp;
		range[i]=idx;
		idx++;
	}
	sm=0;
	for(int i=0;i<n;i++){
		sm+=cs[i];
		ll tmp=sm-v[i];
		front[i]=tmp;
		
	}
	ll ans=0;
	sm=0;
	build(1,0,n-1);
	for(int i=0;i<n;i++){
	sm+=cs[i];
	ll tmp=sm-v[i];
	ans=max(ans,tmp);
	tmp-=v[i];
	if(i!=n-1){
		l=range[n-1];
		r=range[i+1];
		tmp+=get1(1,0,n-1);
	}
	
	ans=max(ans,tmp);
	}
	sm=0;
	for(int i=n-1;i>=0;i--){
		sm+=cs[i];
		ll tmp=sm-(C-v[i]);
		ans=max(ans,tmp);
		tmp-=(C-v[i]);
		if(i!=0){
			l=0,r=i-1;
			tmp+=get2(1,0,n-1);
		}
		ans=max(ans,tmp);
	}
	cout<<ans<<endl;
	
	
	
	
	
}
