#include<stdio.h>

#define LIMIT 100
#define NIL -1

#define MAX(a,b) (a>b? a:b)

typedef struct{int parent, left, right; }Node;

Node T[LIMIT];
int depth[LIMIT],degree[LIMIT],height[LIMIT];

int getHeight(int x,int h){
	if(T[x].left==NIL && T[x].right==NIL)return h;
	else if(x==-1)return h-1;
	
	int ret=MAX(getHeight(T[x].left,h+1),getHeight(T[x].right,h+1));

	return ret;
}
int getDepth(int x, int d){
	if(T[x].parent==NIL)return d;

	return getDepth(T[x].parent,d+1);
}

void Print(int x){
	int i,c;
	int p=T[x].parent;
	int sibling=T[p].right;
	if(x==sibling)sibling=(T[p]).left;

	if(p==NIL)sibling=-1;
	printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",x,p,sibling,degree[x],depth[x], height[x]);
	if(T[x].parent == NIL)printf("root");
	else if(T[x].left == NIL&&T[x].right==NIL)printf("leaf");
	else printf("internal node");

	printf("\n");
}


int main(){
	int i,j,n,id,l,r;	scanf("%d",&n);
	for(i=0;i<n;i++)T[i].parent=T[i].left=T[i].right=NIL;

	for(i=0;i<n;i++){
		scanf("%d%d%d",&id,&l,&r);
		T[l].parent=T[r].parent=id;

		if(l!=-1){
			T[id].left=l;
			degree[id]++;
		}
		if(r!=-1){
			T[id].right=r;
			degree[id]++;
		}
	}

	for(i=0;i<n;i++){
		height[i]=getHeight(i,0);	
		depth[i]=getDepth(i,0);
		Print(i);
	}


	return 0;
}
