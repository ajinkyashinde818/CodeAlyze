#include<cstdio>
#include<algorithm>
using namespace std;
int n;
long long c,ans,sum[1000005],val[1000005],v[1000005],id[1000005];
void calc(){
	for (int i=n; i>=1; i--){
		sum[i]=sum[i+1]+v[i];
		val[i]=sum[i]-(c-id[i]);
	}
	for (int i=n; i>=1; i--)
		val[i]=max(val[i],val[i+1]);
	long long ss=0;
	for (int i=1; i<=n; i++){
		ss+=v[i];
		ans=max(ans,ss-id[i]);
		ans=max(ans,ss-id[i]*2+val[i+1]);
	}
}
int main(){
	scanf("%d%lld",&n,&c);
	for (int i=1; i<=n; i++)
		scanf("%lld%lld",&id[i],&v[i]);
	calc();
	for (int i=1; i<=n; i++) id[i]=c-id[i];
	for (int i=1; i<=n/2; i++){
		swap(id[i],id[n-i+1]);
		swap(v[i],v[n-i+1]);
	}
	calc();
	printf("%lld\n",ans);
	return 0;
}
