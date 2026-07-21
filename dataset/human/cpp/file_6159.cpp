#include<bits/stdc++.h> 

using namespace std;

typedef long long ll;

const int M = 1e5+ 50;

ll a[M],b[M],x[M],v[M];


int main() {
	ll  n,c;
	scanf("%lld %lld",&n,&c);
	
	for(int i=1;i<=n;i++) scanf("%lld %lld",&x[i],&v[i]);x[n+1] = c;
	
//  shun	
	for(int i=1;i<=n;i++) a[i] = a[i - 1] + (v[i] - (x[i] - x[i-1]));
	for(int i=1;i<=n;i++) a[i] = max(a[i-1],a[i]);

//  ni
	for(int i=n;i>=1;i--) b[i] = b[i+1] + (v[i] - (x[i+1] - x[i]));
	for(int i=n;i>=1;i--) b[i] = max(b[i],b[i+1]);
	
	ll ans = 0;
	for(int i=1;i<=n;i++) {
		ans = max(ans,a[i]);
		ans = max(ans,b[i]);
		ans = max(ans,a[i] - x[i] + b[i+1]);
		ans = max(ans,b[i] - (c - x[i]) + a[i-1]);
	}
	
	printf("%lld\n",ans);
	
}
