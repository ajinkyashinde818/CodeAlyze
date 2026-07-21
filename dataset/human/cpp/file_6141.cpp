#include<bits/stdc++.h>
using namespace std;
const int maxn=100100;
int n;
long long C;
struct node{
	long long x,v;
}a[maxn];
long long ans=0;
long long b[maxn];
long long Max(long long x,long long y){
	return x>y?x:y;
}
void chkmax(long long &x,long long y){
	x=x>y?x:y;
}
void solve(){
	b[0]=0;
	long long s=0;
	for(int i=1;i<=n;i++){
		s+=a[i].v;
		b[i]=Max(b[i-1],s-a[i].x*2);
	}
	s=0;
	chkmax(ans,b[n]);
	for(int i=n;i>=1;i--){
		s+=a[i].v;
		chkmax(ans,b[i-1]+s-(C-a[i].x));
	}
}
int main(){
	scanf("%d",&n);
	scanf("%lld",&C);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&a[i].x,&a[i].v);
	solve();
	for(int i=1;i<=n;i++)
		a[i].x=C-a[i].x;
	reverse(a+1,a+n+1);
	solve();
	printf("%lld\n",ans);
	return 0;
}
