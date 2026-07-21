#include <bits/stdc++.h>
using namespace std;
const int maxn=100010;
typedef long long ll;
int n;
ll s1[maxn],s2[maxn],x[maxn],v[maxn],c,ans;
int main() {
	//freopen("1.txt","r",stdin);
	scanf("%d %lld",&n,&c);
	for (int i=1;i<=n;i++)
		scanf("%lld %lld",&x[i],&v[i]);
	ll tmp=0,lst=0;
	for (int i=1;i<=n;i++) {
		tmp+=v[i]; tmp-=x[i]-lst;
		lst=x[i];
		s1[i]=max(s1[i-1],tmp);
	}
	tmp=0; lst=c;
	for (int i=n;i>=1;i--) {
		tmp+=v[i]; tmp-=lst-x[i];
		lst=x[i];
		s2[i]=max(s2[i+1],tmp);
	}
	for (int i=0;i<=n;i++) {
		//printf("%lld %lld\n",s1[i],s2[i]);
		ans=max(ans,s1[i]);
		ans=max(ans,s2[i]);
		tmp=s1[i]+s2[i+1]-x[i];
		ans=max(ans,tmp);
		tmp=s2[i]+s1[i-1]-(c-x[i]);
		ans=max(ans,tmp);
	}
	printf("%lld\n",ans);
	return 0;
}
