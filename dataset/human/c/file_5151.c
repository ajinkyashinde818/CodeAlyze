#include<stdio.h>
#define MAX 10000
#define NIL -1

typedef struct Node{
	int parent,l,r;
}Node;

Node T[MAX];
int n,D[MAX],H[MAX];

void setdepth(int u,int d);
int setheight(int u);
int getsibling(int u);

void print(int u);

int main(void){
	int v,l,r,root = 0;
	
	scanf("%d",&n);
	
	for(int i = 0;i<n;i++){
		T[i].parent = NIL;
	}
	
	for(int i = 0;i < n;i++){
		scanf("%d %d %d",&v,&l,&r);
		T[v].l = l;
		T[v].r = r;
		if(l != NIL) T[l].parent = v;
		if(r != NIL) T[r].parent = v;
	}
	
	for(int i = 0;i < n; i++){
		if(T[i].parent == NIL)root =i;
	}
	
	setdepth(root,0);
	setheight(root);
	
	for(int i = 0;i < n;i++){
		print(i);
	}
	
	return 0;
	
}

void setdepth(int u,int d){
	if(u == NIL)return;
	D[u] = d;
	setdepth(T[u].l,d+1);
	setdepth(T[u].r,d+1);
}

int setheight(int u){
	int h1 = 0;
	int h2 = 0;
	if(T[u].l != NIL)h1 = setheight(T[u].l)+1;
	if(T[u].r != NIL)h2 = setheight(T[u].r)+1;
	H[u] = (h1 > h2 ? h1 : h2);
	return H[u];
}

int getsibling(int u){
	if(T[u].parent == NIL) return NIL;
	if(T[T[u].parent].l != u && T[T[u].parent].l != NIL)return T[T[u].parent].l;
	if(T[T[u].parent].r != u && T[T[u].parent].r != NIL)return T[T[u].parent].r;
	return NIL;
}

void print(int u){
	printf("node %d: ",u);
	printf("parent = %d, ",T[u].parent);
	printf("sibling = %d, ",getsibling(u));
	int deg = 0;
	if(T[u].l != NIL)deg++;
	if(T[u].r != NIL)deg++;
	printf("degree = %d, ",deg);
	printf("depth = %d, ",D[u]);
	printf("height = %d, ",H[u]);
	
	if(T[u].parent == NIL) printf("root\n");
	else if(T[u].l == NIL && T[u].r == NIL) printf("leaf\n");
	else printf("internal node\n");
}
