#include<stdio.h>
#include<stdlib.h>

typedef struct TREE{
	int id;
	int depth;
	int k;
	struct TREE *parent;
	struct TREE **child;
}Tree;

Tree tree[100000];

void setDepth(Tree *nt, int depth){
	int i;
	if( nt == NULL ){ return; }
	nt->depth = depth;
	for( i = 0; i < nt->k; i++ ){
		setDepth(nt->child[i], depth+1);
	}
	return;
}

void print(Tree *p){
	int parent, nodetype, i;
	char *nodename[] = {"root", "internal node", "leaf"};
	if( p == NULL ){ return; }
	if( p->parent == NULL ){
		parent = -1;
	}else{
		parent = p->parent->id;
	}
	if( parent == -1 ){
		nodetype = 0;
	}else if( p->k > 0 ){
		nodetype = 1;
	}else{
		nodetype = 2;
	}
	printf("node %d: parent = %d, depth = %d, ", p->id, parent, p->depth);
	printf("%s, ", nodename[nodetype]);
	printf("[");
	if( p->k > 0 ){
		printf("%d", p->child[0]->id);
		for( i = 1; i < p->k; i++ ){
			printf(", %d", p->child[i]->id);
		}
	}
	printf("]\n");
	return;
}

int main(){
	int n, id, id2, i, j;
	scanf("%d", &n);
	Tree *root = NULL;
	for( i = 0; i < n; i++ ){
		tree[i].id = i;
		tree[i].parent = NULL;
		tree[i].child = NULL;
		tree[i].k = -1;
		tree[i].depth = -1;
	}
	for( i = 0; i < n; i++ ){
		scanf("%d", &id);
		scanf("%d", &tree[id].k);
		tree[id].child = (Tree**)malloc(sizeof(Tree*)*tree[id].k);
		for( j = 0; j < tree[id].k; j++ ){
			scanf("%d", &id2);
			tree[id].child[j] = &tree[id2];
			tree[id2].parent = &tree[id];
		}
	}
	//???????±??????????
	for( i = 0; i < n; i++ ){
		if( tree[i].parent == NULL ){
			root = &tree[i];
			break;
		}
	}
	//??±???????±??????????
	setDepth(root, 0);
	//???????????????
	for( i = 0; i < n; i++ ){ print(&tree[i]); }
	return 0;
}
