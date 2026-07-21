#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
	int child_len;
	int *child;
	int parent;
}NODE;

int calc_depth(NODE node[],int num,int depth){
	if(node[num].parent==-1){
		return depth;
	}
	int d=calc_depth(node,node[num].parent,depth+1);
	return d;
}

char *calc_type(NODE node){
	if(node.parent==-1){
		return "root";
	}
	if(node.child_len==0){
		return "leaf";
	}
	return "internal node";
}



int main(){
	int N,num;
	NODE *node;

	scanf("%d",&N);
	node=(NODE*)malloc(sizeof(NODE)*N);
	for(int i=0;i<N;i++){
		node[i].parent=-1;
	}
	for(int i=0;i<N;i++){
		scanf("%d",&num);
		scanf("%d",&node[num].child_len);
		node[num].child=(int*)malloc(sizeof(int)*node[num].child_len);
		for(int j=0;j<node[num].child_len;j++){
			scanf("%d",&node[num].child[j]);
			node[node[num].child[j]].parent=num;
		}
	}

	
	for(int i=0;i<N;i++){
		printf("node %d: parent = %d, ",i,node[i].parent);
		printf("depth = %d, ",calc_depth(node,i,0));
		printf("%s, ",calc_type(node[i]));
		printf("[");
		for(int j=0;j<node[i].child_len;j++){
			printf("%d",node[i].child[j]);
			if(j!=(node[i].child_len-1)){
				printf(", ");
			}
		}
		printf("]\n");
	}

	
	return 0;
}
