#include<stdio.h>

#define MAX 100010
#define NIL -1

typedef struct{int parent, left, right; }Node;

Node T[MAX];
int depth[MAX];

void Print(int x){
	int i,c;
	printf("node %d: parent = %d, depth = %d, ",x,T[x].parent,depth[x]);
	if(T[x].parent == NIL)printf("root, ");
	else if(T[x].left == NIL)printf("leaf, ");
	else printf("internal node, ");

	printf("[");
	for(i=0,c=T[x].left;	c!=NIL;		i++,c=T[c].right){
		if(i)printf(", ");
		printf("%d",c);
	}
	printf("]\n");
}

void getDepth(int x, int d){
	depth[x]=d;
	if(T[x].right != NIL)getDepth(T[x].right, d);
	if(T[x].left != NIL)getDepth(T[x].left, d+1);
}

int main(){
	int i,j,n,id,k,c,l,r;	scanf("%d",&n);
	for(i=0;i<n;i++)T[i].parent=T[i].left=T[i].right=NIL;

	for(i=0;i<n;i++){
		scanf("%d%d",&id,&k);
		for(j=0;j<k;j++){
			scanf("%d",&c);
			if(j==0)T[id].left=c;
			else T[l].right=c;
			l=c;

			T[c].parent = id;
		}
	}

	for(i=0;i<n;i++){
		if(T[i].parent == NIL){
			getDepth(i,0);
			break;
		}
	}

	for(i=0;i<n;i++)Print(i);


	return 0;
}
