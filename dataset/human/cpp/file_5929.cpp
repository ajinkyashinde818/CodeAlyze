#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
long long n,m,x[100005],y[100005],ans,sum[200005],maxx[200005],maxn[200005];
int main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld%lld",&x[i],&y[i]);
    for(int i=1;i<=n;i++){
    	sum[i]=sum[i-1]+y[i];
	}
	for(int i=n;i>=1;i--){
		maxx[i]=max(maxx[i+1],(sum[n]-sum[i-1])-(m-x[i]));
	}
	for(int i=1;i<=n;i++){
		maxn[i]=max(maxn[i-1],sum[i]-x[i]);
	}
    for(int i=1;i<=n;i++){
    	ans=max(ans,max(sum[i]-2*x[i]+maxx[i+1],sum[i]-x[i]));
    }
    for(int i=n;i>=1;i--){
    //	cout<<sum[n]<<" "<<sum[i-1]<<" "<<m-x[i]<<" "<<maxn[i-1]<<endl;
    	ans=max(ans,(sum[n]-sum[i-1])-(m-x[i])*2+maxn[i-1]);
    	ans=max(ans,sum[n]-sum[i-1]-(m-x[i]));
	}
	cout<<ans<<endl;
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
    return 0;
}
