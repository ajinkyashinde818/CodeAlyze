#include<stdio.h>
#include<stdlib.h>

typedef struct{
  int parent,left,right;
}Node;

void depth(int,int,Node *,int *);

int main(){
 
	int n, *D, *H;
	int i,j,d,c,v,root,left,right;
	Node *T;
 
	scanf("%d",&n);
	
	T=(Node *)malloc(sizeof(Node)*n);
	D=(int *)malloc(sizeof(int)*n);
	H=(int *)malloc(sizeof(int)*n);
    for(i = 0; i<n; i++){
      T[i].parent = T[i].left = T[i].right =-1;
    }
     
    for(i=0; i<n; i++){
      scanf("%d %d",&v,&d);
      for(j=0; j<d; j++){
    scanf("%d",&c);
    if(j==0)
      T[v].left = c;
    else
      T[left].right = c;
    left = c;
    T[c].parent = v;
      }
    }
 
    for(i=0; i<n; i++){
      if(T[i].parent==-1) root = i;
    }
 
    depth(root,0,T,D);
    
 
    for(i=0; i<n; i++){
    	
	printf("node %d: ",i);
	printf("parent = %d, ", T[i].parent);
 	printf("depth = %d, ",D[i]);
 
 	if(T[i].parent==-1){
    printf("root, ");
  	}
  	else if(T[i].left==-1){
    	printf("leaf, ");
  	}
  	else{
    	printf("internal node, ");
  	}
 
  	printf("[");
 
  	for(j=0, c=T[i].left; c!=-1; j++,c=T[c].right){
    	if(j)
      	printf(", ");
    printf("%d",c);
  	}
  	printf("]\n");
}
 
    return 0;
}

void depth(int u, int d,Node *T,int *D){
  D[u] = d;
 
  if(T[u].right != -1) depth(T[u].right, d,T,D);
  if(T[u].left != -1) depth(T[u].left, d+1,T,D);
}
