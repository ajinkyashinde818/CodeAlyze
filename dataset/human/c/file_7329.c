#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define INF 1000000000000
#define min(p,q)((p)<(q)?(p):(q))
#define max(p,q)((p)>(q)?(p):(q))
int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}

ll a[100010];
ll b[100010];
ll la,ra,lb,rb;
int n,nn,q;

void f(ll x){
	int l=0,r=n;
	while(r-l>1){
		int m=(l+r)/2;
		if(a[m]<=x)l=m;
		else r=m;
	}
	if(a[l]==x){
		la=ra=a[l];
	}else{
		la=a[l];
		ra=a[l+1];
	}

	l=0,r=nn;
	while(r-l>1){
		int m=(l+r)/2;
		if(b[m]<=x)l=m;
		else r=m;
	}
	if(b[l]==x){
		lb=rb=b[l];
	}else{
		lb=b[l];
		rb=b[l+1];
	}

}

int main(){
	scanf("%d%d%d",&n,&nn,&q);
	for(int i=0;i<n;i++)scanf("%lld",a+i);
	a[n]=-INF,a[n+1]=INF;
	n+=2;
	sortup(a,n);
	for(int i=0;i<nn;i++)scanf("%lld",b+i);
	b[nn]=-INF,b[nn+1]=INF;
	nn+=2;
	sortup(b,nn);
	while(q--){
		ll x;
		scanf("%lld",&x);
		f(x);
		ll ans=min(min(min(
			x-min(la,lb),
			max(ra,rb)-x  ),
			(x-la)+(rb-x)+min(x-la,rb-x)  ),
			(x-lb)+(ra-x)+min(x-lb,ra-x)  );
		printf("%lld\n",ans);
	}
}
