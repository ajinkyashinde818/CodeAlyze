#include<stdio.h>

#define MAX 100005
#define NIL -1

typedef struct { int parent, left, right; } Node;

Node T[MAX];
int n, D[MAX];

void print(int u){
	int i, c;
	printf("node %d: parent = %d, depth = %d, ", u, T[u].parent, D[u]);
	
	if(T[u].parent == NIL) printf("root, ");
	else if(T[u].left == NIL) printf("leaf, ");
	else printf("internal node, ");
	
	printf("[");
	
	for(i = 0, c = T[u].left; c != NIL; i++, c = T[c].right){
		if(i) printf(", ");
		printf("%d", c);
	}
	
	printf("]\n");
}

void setDepth(int u, int p){
	D[u] = p;
	if(T[u].right != NIL) setDepth(T[u].right, p);
	if(T[u].left != NIL) setDepth(T[u].left, p+1);
}

int main(void){
	
	int i, j, d, v, c, l, r;
	
	scanf("%d",&n);
	
	for(i = 0; i < n; i++) T[i].parent = T[i].left = T[i].right = NIL;
	
	for(i = 0; i < n; i++){
		scanf("%d %d",&v,&d);
		for(j = 0; j < d; j++){
			scanf("%d",&c);
			if(j == 0) T[v].left = c;
			else T[l].right = c;
			l = c;
			T[c].parent = v;
		}
	}
	
	for(i = 0; i < n; i++){
		if(T[i].parent == NIL) r = i;
	}
	
	setDepth(r, 0);
	
	for(i = 0; i < n; i++) print(i);
	
	return 0;
}
