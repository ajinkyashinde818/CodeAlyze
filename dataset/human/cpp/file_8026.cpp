#include<bits/stdc++.h>
using namespace std;
const int N=200005;
typedef long long ll;
ll a[N],sum[N];
int main() {
	int n;
	scanf("%d",&n);
	sum[0]=0;
	for(int i=1;i<=n;++i) {
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	ll ans=1e18+7;
    for(int i=1;i<=n-1;++i) {
        ans=min(ans,abs(sum[i]-sum[n]+sum[i]));
    }
    cout<<ans<<endl;
	return 0;
}
