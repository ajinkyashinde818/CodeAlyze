#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}
#define MOD 1000000007

ll m[200010],p[200010];
int mcnt,pcnt;
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	rep(i,0,n){
		int t;
		scanf("%d",&t);
		if(t>=0)p[pcnt++]=t;
		else m[mcnt++]=-t;
	}
	//正の数・負の数をそれぞれソート
	sortup(m,mcnt);
	sortup(p,pcnt);
	
	//K==Nのとき
	if(k==n){
		ll ans=1;
		rep(i,0,mcnt)ans=ans*(MOD-m[i])%MOD;
		rep(i,0,pcnt)ans=ans*p[i]%MOD;
		printf("%lld",ans);
		return 0;
	}
	
	//Kが奇数かつ負のみのとき
	if(k%2==1&&mcnt==n){
		ll ans=1;
		rep(i,0,k)ans=ans*(MOD-m[i])%MOD;		
		printf("%lld",ans);
		return 0;
	}
	
	ll ans=1;
	while(k){
		// 負の数を2個とる or 正の数を1個とる
		if(k>=2 && mcnt>=2 &&(pcnt<=1 || (pcnt>=2 && m[mcnt-1]*m[mcnt-2]>=p[pcnt-1]*p[pcnt-2]))){
			ans=ans*m[--mcnt]%MOD;
			ans=ans*m[--mcnt]%MOD;
			k-=2;
		}else{
			ans=ans*p[--pcnt]%MOD;
			k--;
		}
	}
	printf("%lld",ans);
}
