/*
left-child,right-sibling representation
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int p;	//parent
	int l;	//left_child
	int r; 	//right_sibling
}Node;

int main(void){
	int now_id,depth_cnt,n,k,c;
	int i,j;
	Node *node;

	scanf("%d",&n);

	node=(Node*)malloc(n*sizeof(Node));

	for(i=0;i<n;i++){
		node[i].p=-1;
		node[i].l=-1;
		node[i].r=-1;
	}

	for(i=0;i<n;i++){
		scanf("%d",&now_id);
		scanf("%d",&k);

		for(j=0;j<k;j++){
			if(j==0){
				 scanf("%d",&c);
				 node[now_id].l=c;
			}
			else{
				 scanf("%d",&node[c].r);
				 c=node[c].r;
			}
			node[c].p=now_id;
		}
	}

	for(i=0;i<n;i++){
		printf("node %d: ",i);
		printf("parent = %d, ",node[i].p);

		depth_cnt=0;
		now_id=i;
		while(node[now_id].p != -1){
			depth_cnt++;
			now_id=node[now_id].p;
		}
		printf("depth = %d, ",depth_cnt);

		if(node[i].p==-1) printf("root, ");
		else if(node[i].l==-1) printf("leaf, ");
		else printf("internal node, ");

		printf("[");
		if(node[i].l!=-1){
			now_id=node[i].l;
			printf("%d",now_id);
			while(node[now_id].r!=-1){
				now_id=node[now_id].r;
				printf(", %d",now_id);
			}
		}
		printf("]\n");
	}

	return 0;
}
