#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long LL;
const int N=1e5+5;

int n;
LL c,x[N],v[N];
LL a[N],b[N],pa[N],pb[N];

int main() {
	scanf("%d %lld",&n,&c);
	for(int i=1;i<=n;i++) {
		scanf("%lld %lld",&x[i],&v[i]);
	}
	x[n+1]=c;
	LL ans=0;
	for(int i=1;i<=n;i++) {
		a[i]=a[i-1]+v[i]-(x[i]-x[i-1]);
		ans=max(ans,a[i]);
		pa[i]=max(pa[i-1],a[i]);
	}
	for(int i=n;i>0;i--) {
		b[i]=b[i+1]+v[i]-((c-x[i])-(c-x[i+1]));
		ans=max(ans,b[i]);
		pb[i]=max(pb[i+1],b[i]);
	}
	for(int i=1;i<n;i++) {
		ans=max(ans,a[i]-x[i]+pb[i+1]);
	}
	for(int i=n;i>1;i--) {
		ans=max(ans,b[i]-(c-x[i])+pa[i-1]);
	}
	printf("%lld\n",ans);
}
