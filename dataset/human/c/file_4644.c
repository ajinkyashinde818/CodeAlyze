#include <stdio.h>
#include <stdlib.h>
int H[30] = {},D[30] = {};
typedef struct Node{
	int p;
	int l;
	int r;
}Node;

int getSib(Node *t,int u){
	if(t[u].p == -1)return -1;
	if(t[t[u].p].l != u)return t[t[u].p].l;
	if(t[t[u].p].r != u)return t[t[u].p].r;
}

int getDeg(Node *t,int u){
	int deg = 0;
	if(t[u].l != -1)deg++;
	if(t[u].r != -1)deg++;
	return deg;
}

int setHeight(Node *t,int u){
	int h1,h2;
	h1=h2=0;
	if(t[u].l != -1)h1=setHeight(t,t[u].l)+1;
	if(t[u].r != -1)h2=setHeight(t,t[u].r)+1;
	return H[u] = (h1>h2)?h1:h2;
}

void setDepth(Node *t,int u){
	D[t[u].l]=D[t[u].r]=D[u]+1;
	if(t[u].l != -1)setDepth(t,t[u].l);
	if(t[u].r != -1)setDepth(t,t[u].r);
}

void print(Node *t,int n){
	for(int i=0; i<n; i++){
		printf("node %d: ",i);
		printf("parent = %d, ",t[i].p);
		printf("sibling = %d, ",getSib(t,i));
		printf("degree = %d, ",getDeg(t,i));
		printf("depth = %d, ",D[i]);
		printf("height = %d, ",H[i]);
		if(t[i].p == -1)printf("root\n");
		else if(t[i].l == -1 && t[i].r == -1)printf("leaf\n");
		else printf("internal node\n");
	}
}

int main(void) {
	Node *T;
	int n;
	int id;
	int root;
	scanf("%d",&n);
	T = malloc(sizeof(Node) * n + 1);
	for(int i = 0; i < n; i++)T[i].p = T[i].l = T[i].r =-1;
	for(int i = 0; i < n; i++){
		scanf("%d",&id);
		scanf("%d%d",&T[id].l,&T[id].r);
		T[T[id].l].p = T[T[id].r].p = id;
	}
	for(int i = 0; i < n; i++)if(T[i].p == -1)root = i;
	setHeight(T,root);
	setDepth(T,root);
	print(T,n);
	return 0;
}
