#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
	int parent;
	int left,right;
}NODE;

int calc_sibling(NODE *node,int x){
	if(node[x].parent==-1){
		return -1;
	}
	int parent=node[x].parent;
	if(node[parent].left==x){
		return node[parent].right;
	}else{
		return node[parent].left;
	}
}

int calc_degree(NODE *node,int x){
	int count=0;
	if(node[x].left!=-1){
		count++;
	}
	if(node[x].right!=-1){
		count++;
	}
	return count;
}

int calc_depth(NODE *node,int x){
	int depth=0;
	while(node[x].parent!=-1){
		x=node[x].parent;
		depth++;
	}
	return depth;
}

int calc_high(NODE *node,int x,int high){
	int L=0,R=0;

	if(node[x].left==-1 && node[x].right==-1){
		return high;
	}
	
	if(node[x].left!=-1){
		L=calc_high(node,node[x].left,high+1);
	}
	if(node[x].right!=-1){
		R=calc_high(node,node[x].right,high+1);
	}
	if(L<R){
		return R;
	}else{
		return L;
	}
}

char *calc_type(NODE *node,int x){
	if(node[x].parent==-1){
		return "root";
	}
	if(node[x].left==-1 && node[x].right==-1){
		return "leaf";
	}
	return "internal node";
}

int main(){
	int N;
	NODE *node;
	int number,left,right;

	scanf("%d",&N);
	node=(NODE*)malloc(sizeof(NODE)*N);

	for(int i=0;i<N;i++){
		node[i].parent=-1;
		node[i].left=-1;
		node[i].right=-1;
	}
	for(int i=0;i<N;i++){
		scanf("%d %d %d",&number,&left,&right);
		node[number].left=left;
		node[number].right=right;
		if(left!=-1){
			node[left].parent=number;
		}
		if(right!=-1){
			node[right].parent=number;
		}
	}

	for(int i=0;i<N;i++){
		printf("node %d: parent = %d, ",i,node[i].parent);
		printf("sibling = %d, ",calc_sibling(node,i));
		printf("degree = %d, ",calc_degree(node,i));
		printf("depth = %d, ",calc_depth(node,i));
		printf("height = %d, ",calc_high(node,i,0));
		printf("%s",calc_type(node,i));
		printf("\n");
	}

	return 0;
}
