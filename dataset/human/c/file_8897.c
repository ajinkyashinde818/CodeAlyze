#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

ll h,w;
ll d[]={0,1,0,-1,0};
char s[99][99];
int main(){
	scanf("%lld%lld\n",&h,&w);
	rep(i,0,h)scanf("%s",s[i+1]+1);
	ll ans=1;
	rep(i,1,h+1)rep(j,1,w+1)if(s[i][j]=='#'){
		ll flag=0;
		rep(k,0,4)flag|=s[i+d[k]][j+d[k+1]]=='#';
		ans&=flag;
	}
	puts(ans?"Yes":"No");
}
