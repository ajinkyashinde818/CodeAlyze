#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100005;
LL n,C,x[N],t[N],sum[N],ans1[N],ans2[N],ans3[N],ans4[N];
int main(){
	scanf("%lld%lld",&n,&C);
	for (int i=1;i<=n;i++){
		scanf("%lld%lld",&x[i],&t[i]);
		sum[i]=sum[i-1]+t[i];
	}
	ans1[0]=0;
	for (int i=1;i<=n;i++){
		ans1[i]=max(ans1[i-1],sum[i]-x[i]);
		ans3[i]=max(ans3[i-1],sum[i]-x[i]*2);
	}
	ans2[n+1]=0;
	for (int i=n;i>=1;i--){
		ans2[i]=max(ans2[i+1],sum[n]-sum[i-1]-(C-x[i]));
		ans4[i]=max(ans4[i+1],sum[n]-sum[i-1]-(C-x[i])*2);
	}
	LL res=0;
	for (int i=1;i<=n+1;i++)
		res=max(res,max(ans1[i-1]+ans4[i],ans3[i-1]+ans2[i]));
	printf("%lld",res);
	return 0;
}
