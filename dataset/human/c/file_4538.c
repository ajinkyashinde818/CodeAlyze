#include<stdio.h>

const int LIMIT=100001;
const int NIL=-1;
struct node{
	int p,right,left,depth,height,sibling;
};
node Tree[LIMIT];

int calc_depthAndHeight(int p,int deep){
 	if(Tree[p].left==NIL&&Tree[p].right==NIL){
		Tree[p].depth=deep;
		Tree[p].height=0;
		return 1;
	}else{
		int h1=-1,h2=-1,h3;
		if(Tree[p].left!=NIL)h1=calc_depthAndHeight(Tree[p].left,deep+1);
		if(Tree[p].right!=NIL)h2=calc_depthAndHeight(Tree[p].right,deep+1);
		h3=h1>h2?h1:h2;
		Tree[p].height=h3;
		Tree[p].depth=deep;
		return h3+1;
	}
} 
 
void print(int n){
	for(int i=0;i<n;i++){
		printf("node %d: parent = %d, sibling = %d, ",i,Tree[i].p,Tree[i].sibling);
		int degree=(Tree[i].left!=-1)+(Tree[i].right!=-1);
		printf("degree = %d, depth = %d, height = %d, ",degree,Tree[i].depth,Tree[i].height);
		if(Tree[i].p==-1){
			printf("root\n");
		}else if(degree==0){
 			printf("leaf\n");
		}else{
			printf("internal node\n");
		}
	}
}

int main(){
	int n,l,r,no;
	scanf("%d",&n);
	for(int i=0;i<n;i++)Tree[i].p=Tree[i].sibling=NIL;
	for(int i=0;i<n;i++){
 		scanf("%d %d %d",&no,&l,&r);
		Tree[no].left=l;
		Tree[no].right=r;
		Tree[l].p=Tree[r].p=no;
		Tree[l].sibling=r;
		Tree[r].sibling=l;
	}
 	int p=0;
	for(int i=0;i<n;i++)if(Tree[i].p==NIL)p=i;
	int t=calc_depthAndHeight(p,0);
	print(n);
}
