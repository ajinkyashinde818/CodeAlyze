#include<cstdio>
#include<iostream>
using namespace std;

typedef long long LL;

const int MaxN=1e5+5;

int N;
LL C,Ans;
int V[MaxN];
LL X[MaxN],Pre[MaxN],Suf[MaxN],F[MaxN],G[MaxN];

int main(){
	int i;
	scanf("%d%lld",&N,&C);
	for(i=1;i<=N;i++){
		scanf("%lld%d",&X[i],&V[i]);
		Pre[i]=Pre[i-1]+V[i];
		F[i]=max(F[i-1],Pre[i]-X[i]);
	}
	for(i=N;i;i--){
		Suf[i]=Suf[i+1]+V[i];
		G[i]=max(G[i+1],Suf[i]-(C-X[i]));
	}
	for(i=1;i<=N;i++)
		Ans=max(Ans,max(Pre[i]-X[i],Pre[i]-2*X[i]+G[i+1]));
	for(i=N;i;i--)
		Ans=max(Ans,max(Suf[i]-(C-X[i]),Suf[i]-2*(C-X[i])+F[i-1]));
	printf("%lld\n",Ans);
	return 0;
}
