#include<stdio.h>

typedef struct TREE{
	int id;
	struct TREE *parent;
	struct TREE *child[2];
	int depth;
	int height;
}Tree;

Tree tree[100];

int setDepthHeight(Tree *nt, int depth){
	if( nt == NULL ){ return -1; }
	nt->depth = depth;
	int lh = setDepthHeight(nt->child[0], depth+1);
	int rh = setDepthHeight(nt->child[1], depth+1);
	nt->height = (lh>rh?lh:rh) + 1;
	return nt->height;
}

void output(Tree *tr){
	char *nodetype[3] = {"root", "internal node", "leaf"};
	int pid, sibling = -1, degree = 0, ni;
	if( tr->child[0] != NULL ) degree++;
	if( tr->child[1] != NULL ) degree++;
	if( tr->parent != NULL ){
		if( tr->parent->child[0] != NULL && tr->parent->child[0]->id != tr->id ){
			sibling = tr->parent->child[0]->id;
		}
		else if( tr->parent->child[1] != NULL && tr->parent->child[1]->id != tr->id ){
			sibling = tr->parent->child[1]->id;
		}
		if( degree == 0 ){
			ni = 2;
		}else{
			ni = 1;
		}
		pid = tr->parent->id;
	}else{
		ni = 0;
		pid = -1;
	}
	printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n", 
		tr->id, pid, sibling, degree, tr->depth, tr->height, nodetype[ni]
	);
	return;
}

int main(){
	int n, id, id2, i, j;
	Tree *root = NULL;
	scanf("%d", &n);
	for( i = 0; i < n; i++ ){
		tree[i].id = -1;
		tree[i].parent = NULL;
		tree[i].child[0] = NULL;
		tree[i].child[1] = NULL;
		tree[i].depth = -1;
		tree[i].height = -1;
	}
	for(i=0;i<n;i++){
		scanf("%d",&id);
		tree[id].id=id;
		scanf("%d",&id2);
		if(0<=id2 && id2<n){
			tree[id].child[0] = &tree[id2];
			tree[id2].parent = &tree[id];
		}
		scanf("%d",&id2);
		if(0<=id2 && id2 < n ){
			tree[id].child[1] = &tree[id2];
			tree[id2].parent = &tree[id];
		}
	}
	for(i=0;i<n;i++){
		if(tree[i].parent==NULL){
			root = &tree[i];
			break;
		}
	}
	setDepthHeight(root, 0);
	for( i = 0; i < n; i++ ) output(&tree[i]);
	return 0;
}
