#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=100010;
ll x[maxn],v[maxn],sum_v[maxn];
ll seg[maxn*4];
void modify(int l,int r,int pos,ll val,int idx){
	if(l==r) seg[idx]=val;
	else{
		int mid=(l+r)>>1;
		if(pos<=mid) modify(l,mid,pos,val,idx<<1);
		else modify(mid+1,r,pos,val,idx<<1|1);
		seg[idx]=max(seg[idx<<1],seg[idx<<1|1]);
	}
}
ll query(int l,int r,int ql,int qr,int idx){
	if(l==ql && r==qr) return seg[idx];
	int mid=(l+r)>>1;
	if(qr<=mid) return query(l,mid,ql,qr,idx<<1);
	else if(ql>mid) return query(mid+1,r,ql,qr,idx<<1|1);
	return max(query(l,mid,ql,mid,idx<<1),query(mid+1,r,mid+1,qr,idx<<1|1));
}
int main(){
	int n;
	ll c;
	scanf("%d%lld",&n,&c);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",x+i,v+i);
		sum_v[i]=sum_v[i-1]+v[i];
	}
	for(int i=1;i<=n;i++)
		modify(1,n,i,sum_v[n]-sum_v[i-1]-(c-x[i]),1);
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,sum_v[i]-x[i]);
		if(i<n) ans=max(ans,sum_v[i]-x[i]-x[i]+query(1,n,i+1,n,1));
	}
	reverse(x+1,x+1+n);
	reverse(v+1,v+1+n);
	for(int i=1;i<=n;i++){
		x[i]=c-x[i];
		sum_v[i]=sum_v[i-1]+v[i];
	}
	for(int i=1;i<=n;i++)
		modify(1,n,i,sum_v[n]-sum_v[i-1]-(c-x[i]),1);
	for(int i=1;i<=n;i++){
		ans=max(ans,sum_v[i]-x[i]);
		if(i<n) ans=max(ans,sum_v[i]-x[i]-x[i]+query(1,n,i+1,n,1));
	}
	printf("%lld\n",ans);
	return 0;
}
