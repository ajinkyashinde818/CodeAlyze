#include<stdio.h>
#define NIL -1

int D[100001];
struct tree{
	int p,l,r;
}T[100001];

void gd(int i,int p){
	D[i] = p;
	if(T[i].r!=NIL) gd(T[i].r,p);
	if(T[i].l!=NIL) gd(T[i].l,p+1);
}

void ppt(int n){
	printf("node %d: parent = %d, depth = %d, ",n,T[n].p,D[n]);
	if(T[n].p == NIL){
		printf("root, ");
	}
	else if(T[n].l != NIL){
		printf("internal node, ");
	}
	else if(T[n].l == NIL){
		printf("leaf, ");
	}
	printf("[");
	n=T[n].l;
	while(n!=NIL){
		printf("%d",n);
		n=T[n].r;
		if(n != NIL){
			printf(", ");
		}
	}
	printf("]\n");
}

int main(){
	int i,j,n,k,o,cur,num;
	scanf("%d",&o);
	k=o;
	for( i = 0; i < o; i++ ) T[i].p=T[i].l=T[i].r=NIL;
	while(k--){
		scanf("%d %d",&cur,&n);
		if(n){
			scanf("%d",&num);
			T[cur].l=num;
			T[num].p=cur;	
		}
		for( i = 1; i < n; i++ ){
			scanf("%d",&j);
			T[num].r=j;
			T[j].p=cur;
			num=j;
		}
	}
	for(i=0;i<o;i++){
		if(T[i].p==NIL) break;
	}
	gd(i,0);
	for( i = 0; i < o; i++ ) ppt(i);
	return 0;	
}
