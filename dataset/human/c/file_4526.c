#include <stdio.h>

#define N 25
#define NILL -1

struct Tree{int parent,right,left;};

struct Tree T[N];
int D[N];
int H[N];
int n;
int root;

void setdepth(int u,int p){
	D[u] = p;
	if(T[u].left != NILL) setdepth(T[u].left,p+1);
	if(T[u].right != NILL) setdepth(T[u].right,p+1);
}

int  Height(int u){
	int h1,h2;
	h1 = h2 = 0;
	if(T[u].right != NILL) h1 = Height(T[u].right) + 1;
	if(T[u].left != NILL) h2 = Height(T[u].left) + 1;
	if(h1 > h2) H[u] = h1;
	else H[u] = h2;
	return H[u];
}

void tree(){
	setdepth(root,0);
	Height(root);
	int i,j;
	int sib,deg;
	for(i=0;i<n;i++){
		printf("node %d: parent = %d, ",i,T[i].parent);
		sib = -1;
		deg =0;
		for(j=0; j<n; j++){
			if(i != j && D[i] == D[j] && T[i].parent == T[j].parent) {
				sib = j;
				break;
			}
		}
		if(T[i].right!=NILL) deg++;
		if(T[i].left!= NILL) deg++;
		printf("sibling = %d, ",sib);
		printf("degree = %d, ",deg);
		printf("depth = %d, height = %d, ",D[i],H[i]);
		if(T[i].parent== NILL) printf("root\n");
		else if(T[i].left!= NILL || T[i].right!= NILL) printf("internal node\n");
		else printf("leaf\n");
	}
}
int main(){
	scanf("%d",&n);
	int i;
	int id,l,r;
	for(i=0;i<n;i++) T[i].parent = NILL;
	for(i=0;i<n;i++){
		scanf("%d",&id);
		scanf("%d%d",&l,&r);
		T[id].left = l;
		T[id].right = r;
		if(l != NILL) T[l].parent = id;
		if(r != NILL) T[r].parent = id;
	}
	for(i=0;i<n;i++)if(T[i].parent == NILL) root = i;
	tree();
}
