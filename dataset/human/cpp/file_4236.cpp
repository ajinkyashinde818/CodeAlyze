#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5+5;

int N,K,Ans;
int A[MaxN],B[MaxN],X[MaxN],Y[MaxN],Tmp[MaxN<<1];
int Fa[MaxN];

int Get_Fa(int x){
	return x==Fa[x]?x:Fa[x]=Get_Fa(Fa[x]);
}

int main(){
	int i,r1,r2;
	scanf("%d",&N),N++;
	for(i=1;i<N;i++){
		scanf("%d",&A[i]);
		A[N]^=A[i];
	}
	for(i=1;i<N;i++){
		scanf("%d",&B[i]);
		B[N]^=B[i];
	}
	memmove(X,A,sizeof(X));
	memmove(Y,B,sizeof(Y));
	sort(X+1,X+N+1);
	sort(Y+1,Y+N+1);
	for(i=1;i<N;i++)
		if(X[i]^Y[i]){
			puts("-1");
			return 0;
		}
	for(i=1;i<=N;i++)
		if(A[i]^B[i]||i==N){
			Tmp[++K]=A[i],Tmp[++K]=B[i];
			Ans+=(i<N);
		}
	if(!Ans){
		puts("0");
		return 0;
	}
	sort(Tmp+1,Tmp+K+1);
	K=unique(Tmp+1,Tmp+K+1)-Tmp-1;
	for(i=1;i<=K;i++)
		Fa[i]=i;
	for(i=1;i<=N;i++)
		if(A[i]^B[i]){
			A[i]=lower_bound(Tmp+1,Tmp+K+1,A[i])-Tmp;
			B[i]=lower_bound(Tmp+1,Tmp+K+1,B[i])-Tmp;
			if((r1=Get_Fa(A[i]))^(r2=Get_Fa(B[i])))
				Fa[r1]=r2;
		}
	for(i=1;i<=K;i++)
		Ans+=(Get_Fa(i)==i);
	printf("%d\n",Ans-1);
	return 0;
}
