#include<stdio.h>
#define MAX 100000

struct Node{
	int parent;
	int left;
	int right;
};

struct Node T[MAX];
int n, D[MAX], H[MAX];

int setDepth(int u, int d){
	if ( u==-1 ){ return; }
	D[u] = d;
	setDepth(T[u].left, d+1);
	setDepth(T[u].right, d+1);
}

int setHeight(int u){
	int h1=0, h2=0;
	if( T[u].left != -1 ){ h1 = setHeight(T[u].left) + 1; }
	if( T[u].right != -1 ){ h2 = setHeight(T[u].right) + 1; }
	return H[u] = ( h1 > h2 ? h1 : h2 );
}

int getSibling(int u){
	if( T[u].parent == -1 ){ return -1; }
	if( T[T[u].parent].left != u && T[T[u].parent].left != -1 ){
		return T[T[u].parent].left; 
	}
	if( T[T[u].parent].right != u && T[T[u].parent].right != -1 ){
		return T[T[u].parent].right; 
	}
	return -1;
}

void print(int u){
	printf("node %d: parent = %d, sibling = %d, ", u, T[u].parent, getSibling(u));
	
	int deg = 0;
	if( T[u].left != -1 ){ deg++; }
	if( T[u].right != -1 ){ deg++; }
	
	printf("degree = %d, depth = %d, height = %d, ", deg, D[u], H[u]);
	
	if( T[u].parent == -1 ){ printf("root\n"); }
	else if( T[u].left == -1 && T[u].right == -1 ){ printf("leaf\n"); }
	else { printf("internal node\n"); }
}


int main(void){
	int n, i, j;
	int num, left, right, root = 0;
	scanf("%d", &n);
	
	for(i=0; i<n; i++){		//初期化
		T[i].parent = -1;
		T[i].left = -1;
		T[i].right = -1;
	}
	for(i=0; i<n; i++){
		scanf("%d %d %d", &num, &left, &right);
		T[num].left = left;
		T[num].right = right;
		if( left != -1 ){ T[left].parent = num; }
		if( right != -1 ){ T[right].parent = num; }
	}
	for(i=0; i<n; i++){
		if( T[i].parent == -1 ){ root = i; }
	}	
	setDepth(root, 0);
	setHeight(root);
	
	for(i=0; i<n; i++){
		print(i);
	}
	return 0;
}
