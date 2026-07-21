#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define INF ((1LL<<62)-(1LL<<31))
ll pom(ll a,ll n,int m){ll x=1;for(a%=m;n;n/=2)n&1?x=x*a%m:0,a=a*a%m;return x;}
#define invp(a,p)pom(a,p-2,p)
#define MOD 1000000007

int cmp(const void*aa, const void*bb){
	ll a=llabs(*(ll*)aa);
	ll b=llabs(*(ll*)bb);
	return a<b?1:a>b?-1:0;
}

ll a[200010];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	rep(i,0,n)scanf("%lld",a+i);
	//絶対値の降順にソート
	qsort(a,n,sizeof(ll),cmp);
	
	//Kが奇数かつ全てが負
	int neg=1;
	rep(i,0,n)if(a[i]>=0)neg=0;
	if(neg&&k%2==1){
		ll ans=1;
		for(int i=n-1;i>=n-k;i--)ans=ans*(MOD+a[i])%MOD;
		printf("%lld",ans);
		return 0;
	}
	
    //絶対値上位K個の積を計算する
	ll ans=1;
	int sign=0,zero=0;
	rep(i,0,k){
		ans=ans*a[i]%MOD;
		if(a[i]<0)sign^=1;
		if(a[i]==0)zero=1;
	}
	
	//K=Nのときと、絶対値上位K個の積が非負のとき
	if(sign==0||zero||k==n){
		printf("%lld",(ans+MOD)%MOD);
		return 0;
	}
	
	//使ったもののうち、正で絶対値最小、負で絶対値最小を探す
	ll p1=INF,m1=INF;
	rep(i,0,k){
		if(a[i]<0)m1=a[i];
		else p1=a[i];
	}
	
	//使っていないもののうち、非負で絶対値最大、負で絶対値最大を探す
	ll p2=INF,m2=INF;
	for(int i=n-1;i>=k;i--){
		if(a[i]<0)m2=a[i];
		else p2=a[i];
	}
	
	if(p2==INF){
		// 正の数を抜いて負の数を入れるしかない
		ans=ans*invp(p1,MOD)%MOD*(MOD+m2)%MOD;
	}else if(m2==INF || p1==INF){
		// 負の数を抜いて非負の数を入れるしかない
		ans=ans*invp(MOD+m1,MOD)%MOD*p2%MOD;
	}else{
		// 正の数を抜いて負の数を入れる・負の数を抜いて非負の数を入れる
		// どちらがいいか選ぶ
		if(p2*p1>=m2*m1){//p2/m1>=m2/p1
			// 負の数を抜いて非負の数を入れる
			ans=ans*invp(MOD+m1,MOD)%MOD*p2%MOD;
		}else{
			// 正の数を抜いて負の数を入れる
			ans=ans*invp(p1,MOD)%MOD*(MOD+m2)%MOD;
		}
	}
	printf("%lld\n",(ans+MOD)%MOD);
}
