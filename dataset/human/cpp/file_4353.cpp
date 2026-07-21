#include<bits/stdc++.h>
using namespace std;

const int maxN=200005;
int N;
int A[maxN],B[maxN];int *d;
int idA[maxN],idB[maxN];
bool cmp(int u,int v){return d[u]<d[v];}
int mA[maxN],mB[maxN];
int fa[maxN],siz[maxN];int find(int x){return (fa[x]==x)?x:fa[x]=find(fa[x]);}
void merge(int x,int y){x=find(x),y=find(y);if(x==y) return;fa[x]=y,siz[y]+=siz[x];}

int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",&A[i]),A[0]^=A[i],idA[i]=i;
	for(int i=1;i<=N;i++) scanf("%d",&B[i]),B[0]^=B[i],idB[i]=i;
	d=A;sort(idA,idA+N+1,cmp);d=B;sort(idB,idB+N+1,cmp);
	for(int i=0;i<=N;i++){
		if(i==0) mA[idA[i]]=1; else mA[idA[i]]=mA[idA[i-1]]+1-(A[idA[i]]==A[idA[i-1]]);
		if(i==0) mB[idB[i]]=1; else mB[idB[i]]=mB[idB[i-1]]+1-(B[idB[i]]==B[idB[i-1]]);
		if(A[idA[i]]!=B[idB[i]]){printf("-1\n");return 0;}
	} 
	for(int i=1;i<=N+1;i++) fa[i]=i,siz[i]=1;
	int ans=0;
	for(int i=0;i<=N;i++) merge(mA[i],mB[i]),ans+=(mA[i]!=mB[i]);
	for(int i=1;i<=N+1;i++) if(fa[i]==i&&siz[i]>=2) ans+=1;
	if(siz[find(mA[0])]!=1){
		if(mA[0]==mB[0]) ans-=1;
		else ans-=2;
	}
	printf("%d\n",ans);
}
