#include <cstdio>
using namespace std;
typedef long long LL;
const int N=100010;
int n;
LL m;
LL pos[N];
int val[N];
LL fwd[N],bwd[N];
inline LL max(LL x,LL y){
	return x>y?x:y;
}
void readData(){
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld%d",&pos[i],&val[i]);
}
void init(){
	LL sum;
	sum=0;
	fwd[0]=0;
	for(int i=1;i<=n;i++){
		sum+=val[i];
		fwd[i]=max(fwd[i-1],sum-pos[i]);
	}
	sum=0;
	bwd[n+1]=0;
	for(int i=n;i>=1;i--){
		sum+=val[i];
		bwd[i]=max(bwd[i+1],sum-(m-pos[i]));
	}
}
void solve(){
	LL ans=max(fwd[n],bwd[1]);
	LL sum;
	sum=0;
	for(int i=1;i<=n;i++){
		sum+=val[i];
		ans=max(ans,sum-2*pos[i]+bwd[i+1]);
	}
	sum=0;
	for(int i=n;i>=1;i--){
		sum+=val[i];
		ans=max(ans,sum-2*(m-pos[i])+fwd[i-1]);
	}
	printf("%lld\n",ans);
}
int main(){
	readData();
	init();
	solve();
	return 0;
}
