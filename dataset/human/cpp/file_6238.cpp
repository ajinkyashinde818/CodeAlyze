#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const int N=100005;
const int P=998244353;
const long long INF=0x3f3f3f3f3f3f3f3fll;

int n;
long long C,x[N],v[N];
long long cur,ans;
long long s_p[N],s_n[N];
long long f_p[N],f_n[N];

void init(){
	scanf("%d%lld",&n,&C);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&x[i],&v[i]);
	}
	f_p[0]=f_n[n+1]=-INF;
	for(int i=1;i<=n;i++){
		cur+=v[i];
		s_p[i]=cur-x[i];
		f_p[i]=max(f_p[i-1],cur-x[i]);
	}
	cur=0;
	for(int i=n;i>=1;i--){
		cur+=v[i];
		s_n[i]=cur-(C-x[i]);
		f_n[i]=max(f_n[i+1],cur-(C-x[i]));
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,s_p[i]);
		ans=max(ans,s_p[i]-x[i]+f_n[i+1]);
		ans=max(ans,s_n[i]);
		ans=max(ans,s_n[i]-(C-x[i])+f_p[i-1]);
	}
	printf("%lld\n",ans);
}

int main(){
	init();
	return 0;
}
