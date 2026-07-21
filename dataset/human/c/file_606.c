#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

char a[55][55];
char b[55][55];
int main(){
	ll n,m;
	scanf("%lld%lld",&n,&m);
	rep(i,0,n)scanf("%s",a[i]);
	rep(i,0,m)scanf("%s",b[i]);
	rep(i,0,n-m+1)rep(j,0,n-m+1){
		ll flag=1;
		rep(ii,0,m)rep(jj,0,m)if(a[i+ii][j+jj]!=b[ii][jj]){
			flag=0;
			break;
		}
		if(flag){
			puts("Yes");
			return 0;
		}
	}
	puts("No");
}
