#include<stdio.h>
#include<stdlib.h>
#define mymalloc(p,n) {p = malloc((n)*sizeof(*p));if ((p)==NULL) {printf("not enough memory?\n"); exit(1);};}

typedef struct node{
	struct node *parent;
	struct node *right;
	struct node *left;
	int id;
	int degree;
	int depth;
	int height;
	int sibling;
}node;

node *createNode(){
	node *node;
	mymalloc(node,1);
	node->parent=NULL;
	node->right=NULL;
	node->left=NULL;
	node->id=0;
	node->degree=0;
	node->depth=0;
	node->height=0;
	return node;
}

node **readNode(int n){
	int i,id,left,right;
	node **T;
	mymalloc(T,n);
	for(i=0;i<n;i++){
		T[i]=createNode();
	}
	for(i=0;i<n;i++){
		scanf(" %d %d %d",&id,&left,&right);
		T[id]->id=id;
		if(left!=-1){
			T[id]->left=T[left];
			T[left]->parent=T[id];
		}
		if(right!=-1){
			T[id]->right=T[right];
			T[right]->parent=T[id];
		}
	}
	return T;
}

node *returnRoot(node **T,int n){
	int i;
	for(i=0;i<n;i++){
		if(T[i]->parent==NULL){
			return T[i];
		}
	}
}

int calcDepth(node *root,int depth){
	int degree,height1,height2;
	degree=0;height1=0;height2=0;
	root->depth=depth;
	if(root->left!=NULL){
		height1=calcDepth(root->left,depth+1);
		degree++;
	}
	if(root->right!=NULL){
		height2=calcDepth(root->right,depth+1);
		degree++;
	}
	root->degree=degree;
	if(root->degree==0){
		root->height=0;
	}else{
	if(height1>height2){
		root->height=height1+1;
	}else{
		root->height=height2+1;
	}}
	
	return root->height;
}

void printNode(node **T,int n){
	int i;
	node *sibling;
	for(i=0;i<n;i++){
		printf("node %d: ",T[i]->id);
		if(T[i]->parent==NULL){
			printf("parent = -1, ");
			printf("sibling = -1, ");
		}else{
			printf("parent = %d, ",T[i]->parent->id);
			if(T[i]->parent->degree==2){
				if(T[i]->parent->left!=T[i]){
					printf("sibling = %d, ",T[i]->parent->left->id);
				}else{
					printf("sibling = %d, ",T[i]->parent->right->id);
				}
			}else{
				printf("sibling = -1, ");
			}
		}
		printf("degree = %d, ", T[i]->degree);
		printf("depth = %d, ", T[i]->depth);
		printf("height = %d, ", T[i]->height);
		if(T[i]->parent==NULL){
			printf("root\n");
		}else{
		if(T[i]->degree!=0){
			printf("internal node\n");
		}else{
			printf("leaf\n");
		}}
	}
}

void freeNode(node **T,int n){
	int i;
	for(i=0;i<n;i++){
		free(T[i]);
	}
	free(T);
}

main(){
	int n;
	node **T;
	node *root;
	scanf("%d",&n);
	T=readNode(n);
	root=returnRoot(T,n);
	calcDepth(root,0);
	printNode(T,n);
	freeNode(T,n);
	return 0;
}
