#include <stdio.h>

#define N 100000
#define Nill -1

struct Tree{int p,l,r;};
int n;
struct Tree T[N];
int D[N];
void getDepth(int u,int p){
	D[u] = p;
	if(T[u].r!= Nill) getDepth(T[u].r,p);
	if(T[u].l != Nill) getDepth(T[u].l,p+1);
}

void Print(int r){
	getDepth(r,0);
	int i;
	int g;
	for(i=0;i<n;i++){
		printf("node %d: parent = %d, depth = %d, ",i,T[i].p,D[i]);
		if(T[i].p == Nill) printf("root, ");
		else if(T[i].l != Nill) printf("internal node, ");
		else printf("leaf, ");
		if(T[i].l!= Nill){
			printf("[%d",T[i].l);
			g = T[i].l;
			while(1){
				if(T[g].r != Nill)printf(", %d",T[g].r);
				else {
					printf("]\n");
					break;
				}
				g = T[g].r;
			}
		}
		else printf("[]\n");
	}
}

int main(){
	scanf("%d",&n);
	int i,m,c,j;
	for(i=0;i<n;i++)T[i].p=T[i].l=T[i].r=Nill;
	int op,l;
	for(i=0;i<n;i++){
		scanf("%d%d",&m,&c);
		for(j=0;j<c;j++){
			scanf("%d",&op);
			if(j==0)T[m].l = op;
			else	T[l].r = op;
			l = op;
			T[op].p = m;
		}
	}
	for(i = 0;i < n; i++){
		if(T[i].p == Nill) break;
	}
	Print(i);

	return 0;
}
