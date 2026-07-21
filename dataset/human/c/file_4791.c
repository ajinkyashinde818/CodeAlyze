/*
Binary Tree
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int l;	//left child
	int r;	//right child
	int p;	//parent
}Node;

void calc_height(Node*,int,int);

int hei;

int main(void){
	int n,id,sib,deg,dep;
	int i,j;
	int work;
	Node *node;

	scanf("%d",&n);

	node=(Node*)malloc(n*sizeof(Node));

	for(i=0;i<n;i++){
		 node[i].p=-1;
		 node[i].l=-1;
		 node[i].r=-1;
	}

	for(i=0;i<n;i++){
		scanf("%d",&id);
	
		scanf("%d",&node[id].l);
		if(node[id].l != -1) node[node[id].l].p=id;
		
		scanf("%d",&node[id].r);
		if(node[id].r != -1) node[node[id].r].p=id;

	}

	for(i=0;i<n;i++){
		printf("node %d: ",i);

		printf("parent = %d, ",node[i].p);
		
		sib=-1;
		if(node[i].p!=-1){
			if(node[node[i].p].l==i) sib=node[node[i].p].r;
			else sib=node[node[i].p].l;
		}
		printf("sibling = %d, ",sib);

		deg=0;
		if(node[i].l!=-1) deg++;
		if(node[i].r!=-1) deg++;
		printf("degree = %d, ",deg);

		dep=0;
		work=i;
		while(node[work].p!=-1){
			dep++;
			work=node[work].p;
		}
		printf("depth = %d, ",dep);

		hei=0;
		calc_height(node,i,1);
		printf("height = %d, ",hei);
		
		if(node[i].p==-1) printf("root\n");
		else if(node[i].l==-1 && node[i].r==-1) printf("leaf\n");
		else printf("internal node\n");
	}

	free(node);

	return 0;
}


void calc_height(Node node[],int id,int cnt){
	if(node[id].l==-1 && node[id].r==-1) return;
	if(cnt>hei) hei=cnt;
	if(node[id].r!=-1)calc_height(node,node[id].r,cnt+1);
	if(node[id].l!=-1)calc_height(node,node[id].l,cnt+1);	
}
