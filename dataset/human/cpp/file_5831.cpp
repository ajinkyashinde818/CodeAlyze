#include<bits/stdc++.h>
using namespace std;
const int N=100010;
typedef long long ll;
struct data{ll x,v;}t[N];
ll a[N],b[N],c[N],d[N];
inline bool cmp(const data &A,const data &B) {
    return A.x<B.x;
}
int main(){
    int n;
    ll C,ans=0;
    cin>>n>>C;
    for(int i=1;i<=n;i++)
	scanf("%lld%lld",&t[i].x,&t[i].v);
    sort(t+1,t+n+1,cmp);
    ll sum=0;
    for(int i=1;i<=n;i++) {
	sum=sum+t[i].v;
	a[i]=max(a[i-1],sum-t[i].x);
	b[i]=max(b[i-1],sum-t[i].x*2);
    }
    sum=0;
    for(int i=n;i;i--) {
	sum=sum+t[i].v;
	c[i]=max(c[i+1],sum-(C-t[i].x));
	d[i]=max(d[i+1],sum-(C-t[i].x)*2);
    }
    for(int i=1;i<=n;i++) {
	ans=max(ans,max(a[i],c[i]));
	ans=max(ans,a[i-1]+d[i]);
	ans=max(ans,b[i-1]+c[i]);
    }
    cout<<ans;
    return 0;
}
