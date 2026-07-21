#include<stdio.h>
#define NIL -1

int D[100001],H[100001],zero[100001];
struct tree{
	int p,l,r;
}T[100001];

void gd(int i,int p){
	D[i] = p;
	if(T[i].r!=NIL&&(D[T[i].r]==NIL)) gd(T[i].r,p);
	if(T[i].l!=NIL) gd(T[i].l,p+1);
	else if(T[i].l==NIL&&zero[i]!=NIL) gd(zero[i],p+1);
}

void ppt(int n){
	printf("node %d: parent = %d, sibling = %d, degree = ",n,T[n].p,T[n].r);
	if(T[n].l!=NIL&&(T[T[n].l].r!=NIL)) printf("2");
	else if(zero[n]==NIL)printf("0");
	else printf("1");
	printf(", depth = %d, ",D[n]);
	printf("height = %d, ",H[n]);
	if(T[n].p == NIL){
		printf("root\n");
	}
	else if(zero[n]==NIL)printf("leaf\n");
	else printf("internal node\n");
}

void gh(int n,int h){
	if(H[n]){
		H[n] = ( h > H[n] ? h : H[n]);
	}
	int par = T[n].p;
	if(par != NIL){
		H[par] = ( (h+1) > H[par] ? (h+1) : H[par] );
		gh(par,h+1);
	}
}

int main(){
	int i,n,j,k,o,a,b,c;
	scanf("%d",&o);
	k=o;
	for( i = 0; i < k; i++){
		T[i].l=T[i].p=T[i].r=D[i]=NIL;
	}
	while(k--){
		scanf("%d %d %d",&a,&b,&c);
		T[a].l=b;
		T[b].r=c;
		T[b].p=a;
		T[c].p=a;
		T[c].r=b;
		if(b==NIL&&c==NIL) zero[a]=NIL;
		if(b==NIL) zero[a]=c;
		if(c==NIL) zero[a]=b;
	}
	for( i = 0; i < o; i++) 
		if(T[i].p==NIL) break;
	gd(i,0);
	for( i = 0; i < o; i++)
		if(T[i].l==NIL) gh(i,0);
	for( i = 0; i < o; i++) ppt(i);
}
