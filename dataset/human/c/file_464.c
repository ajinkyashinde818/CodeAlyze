#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define bit(n,m)(((n)>>(m))&1)
int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
int downll(const void*a, const void*b){return*(ll*)a<*(ll*)b?1:*(ll*)a>*(ll*)b?-1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}
void sortdown(ll*a,int n){qsort(a,n,sizeof(ll),downll);}
ll pom(ll a,ll n,int m){ll x=1;for(a%=m;n;n/=2)n&1?x=x*a%m:0,a=a*a%m;return x;}
//#define MOD 998244353
#define MOD 1000000007
#define invp(a,p)pom(a,p-2,p)

ll an[200010],bn[200010];
ll ha[200010],hainv[200010],hb[200010],hbinv[200010];

//プラキュー（二分ヒープ）（優先度変更ありバージョン）
int PQhikaku(ll*heap,int i,int j);//jの方が優先度が高いならtrueを返す
void PQchange(ll*heap,ll*heapinv,int n);
void heap_utod(ll*heap,ll*heapinv,int n){
	if(2*n>heap[0])return;
	int rflag=(2*n+1<=heap[0])&&(PQhikaku(heap,2*n,2*n+1));
	if(PQhikaku(heap,n,2*n+rflag)){
		ll temp=heap[2*n+rflag];
		heap[2*n+rflag]=heap[n];
		heap[n]=temp;
		heapinv[heap[n]&0xFFFFFF]=n;
		heapinv[heap[2*n+rflag]&0xFFFFFF]=2*n+rflag;	
		heap_utod(heap,heapinv,2*n+rflag);
	}
}
void heap_dtou(ll*heap,ll*heapinv,int n){
	if(n==1||PQhikaku(heap,n,n/2))return;
	ll temp=heap[n];
	heap[n]=heap[n/2];
	heap[n/2]=temp;
	heapinv[heap[n]&0xFFFFFF]=n;
	heapinv[heap[n/2]&0xFFFFFF]=n/2;
	heap_dtou(heap,heapinv,n/2);
}
ll PQpop(ll*heap,ll*heapinv){
	ll rr=heap[1];
	heapinv[heap[1]&0xFFFFFF]=0;
	heap[1]=heap[heap[0]--];
	heapinv[heap[1]&0xFFFFFF]=1;
	heap_utod(heap,heapinv,1);
	return rr;
}
void PQpush(ll*heap,ll*heapinv,ll n){
	heap[++heap[0]]=n;
	heapinv[heap[heap[0]]&0xFFFFFF]=heap[0];
	heap_dtou(heap,heapinv,heap[0]);
}
//この2つを変える
//*
int PQhikaku(ll*heap,int i,int j){
	if(bit(heap[i],50))return bn[heap[j]&0xFFFFFF]>bn[heap[i]&0xFFFFFF];
	return an[heap[j]&0xFFFFFF]>an[heap[i]&0xFFFFFF];
}
void PQchange(ll*heap,ll*heapinv,int n){
	if(heapinv[n&0xFFFFFF])heap_utod(heap,heapinv,heapinv[n&0xFFFFFF]);
}
//*/


ll a[200010],b[200010];

ll idx[200010];
ll ans[200010];

int main(){
	int n;
	scanf("%d",&n);
	rep(i,0,n)scanf("%lld",a+i);
	rep(i,0,n)scanf("%lld",b+i);
	rep(i,0,n)bn[a[i]]++;
	rep(i,0,n)an[b[i]]++;
	
	rep(i,0,n)if(!idx[a[i]])idx[a[i]]=i+1;
	
	rep(i,1,n+1)if(bn[i])PQpush(ha,hainv,i);
	rep(i,1,n+1)if(an[i])PQpush(hb,hbinv,i|1LL<<50);
	
	rep(_,0,n){
		int i1=PQpop(ha,hainv);
		int j=PQpop(hb,hbinv)&0xFFFFFF;
		//printf("t1:%d %d\n",i1,j);
		if(i1==j){
			if(ha[0]==0){
				puts("No");
				return 0;
			}
			int i2=PQpop(ha,hainv);
			//printf("%d\n",i2);
			if(bn[i2]==0){
				puts("No");
				return 0;
			}
			PQpush(ha,hainv,i1);
			i1=i2;
		}
		//printf("t2:%d %d\n",i1,j);
		ans[-1+idx[i1]++]=j;
		an[j]--;
		bn[i1]--;
		PQchange(ha,hainv,j);
		PQchange(hb,hbinv,i1);
		
		if(bn[i1])PQpush(ha,hainv,i1);
		if(an[j])PQpush(hb,hbinv,j|1LL<<50);
		//rep(i,0,n)printf("%lld ",ans[i]);puts("");
		
	}
	puts("Yes");
	rep(i,0,n)printf("%lld ",ans[i]);
}
