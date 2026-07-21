#include <stdio.h>
#define MAX 10000

typedef struct node{
	int parent,left,right;
}Node;

void setDepth(int,int);
int setHeight(int);
int getSobling(int);
void print(int);


Node tree[MAX];
int n,depth[MAX],height[MAX];

int main(){
	int i,j,v,l,r,root = 0;
	scanf("%d",&n);

	for(i=0;i<n;i++){
		tree[i].parent = -1;
	}
	for(i=0;i<n;i++){
		scanf("%d%d%d",&v,&l,&r);
		tree[v].left = l;
		tree[v].right = r;
		if(l != -1)tree[l].parent = v;
		if(r != -1)tree[r].parent = v;
	}

	for(i=0;i<n;i++){
		if(tree[i].parent == -1) root = i;
	}

	setDepth(root,0);
	setHeight(root);

	for(i=0;i<n;i++){
		print(i);
	}


		return 0;

}



void setDepth(int u,int d){
	if(u == -1)return;
	depth[u] = d;
	setDepth(tree[u].left,d+1);
	setDepth(tree[u].right,d+1);
}	


int setHeight(int u){
	int h1=0,h2=0;
	if(tree[u].left != -1)
		h1 = setHeight(tree[u].left) + 1;
	if(tree[u].right != -1)
		h2 = setHeight(tree[u].right) + 1;
	return height[u] = (h1>h2 ? h1 : h2);
}

int getSobling(int u){
	if(tree[u].parent == -1)return -1;
	if(tree[tree[u].parent].left != u && tree[tree[u].parent].left != -1)
		return tree[tree[u].parent].left;
		if(tree[tree[u].parent].right != u && tree[tree[u].parent].right != -1)
			return tree[tree[u].parent].right;
		return -1;
}

void print(int u){
	int deg = 0;

	printf("node %d: ",u);
	printf("parent = %d, ",tree[u].parent);
	printf("sibling = %d, ",getSobling(u));
	if(tree[u].left != -1)deg++;
	if(tree[u].right != -1)deg++;
	printf("degree = %d, ",deg);
	printf("depth = %d, ",depth[u]);
	printf("height = %d, ",height[u]);

	if(tree[u].parent == -1){
		printf("root\n");
	}else if(tree[u].left == -1 && tree[u].right == -1){
		printf("leaf\n");
	}else{
		printf("internal node\n");
	}
	
}
