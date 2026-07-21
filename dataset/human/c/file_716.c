#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <math.h>
#define rep(i,st,ed) for (int i=st;i<=ed;++i)
#define fill(x,t) memset(x,t,sizeof(x))

typedef long long LL;
const int MOD=1000000007;
const int N=200005;

int cnt[27],n;
LL rc[N],ans;

char str[N];

int read() {
	int x=0,v=1; char ch=getchar();
	for (;ch<'0'||ch>'9';v=(ch=='-')?(-1):(v),ch=getchar());
	for (;ch<='9'&&ch>='0';x=x*10+ch-'0',ch=getchar());
	return x*v;
}

void dfs(int dep,LL xs,int c) {
	if (dep==26) {
		if (c==0) return ;
		ans=(ans+xs)%MOD;
		ans=(ans+MOD)%MOD;
		return ;
	}
	if (cnt[dep]) dfs(dep+1,xs*(cnt[dep])%MOD,c+1);
	dfs(dep+1,xs,c);
}

int main(void) {
	scanf("%d",&n); scanf("%s",str+1);
	rc[0]=1; rep(i,1,N-1) rc[i]=rc[i-1]*2LL%MOD;
	rep(i,1,n) cnt[str[i]-'a']++;
	dfs(0,1,0); ans=(ans%MOD+MOD)%MOD;
	printf("%lld\n", ans);
	return 0;
}
