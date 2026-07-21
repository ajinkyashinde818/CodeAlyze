#include <stdio.h>
#include <stdlib.h>
#define NIL -1

typedef struct node{
  int id;
  int k;
  int parent;
  int *c;
}node;

void printTree(node*,int);
int depth(node*,int,int);

int main(){
  node *tree;
  int i,j,n,id,k;

  scanf("%d",&n);

  tree = (node *)malloc(sizeof(node)*n);

  for(i=0;i<n;i++) tree[i].parent = -1;

  for(i=0;i<n;i++){
    scanf("%d %d",&id,&k);
    tree[id].c = (int *)malloc(k*sizeof(int));
    tree[id].id=id;
    tree[id].k=k;
    for(j=0;j<tree[id].k;j++){
      scanf("%d",&tree[id].c[j]);
      tree[tree[id].c[j]].parent = id;
    }
  }

  printTree(tree,n);
    
  return 0;
}

void printTree(node* tree,int n){
  int i,j,d;
  
  for(i=0;i<n;i++){
    d=depth(tree,i,0);
    printf("node %d: parent = %d, depth = %d, ",i,tree[i].parent,d);
    if(d == 0) printf("root, [");
    else if(tree[i].k == 0) printf("leaf, [");
    else printf("internal node, [");
    for(j=0;j<tree[i].k;j++){
      if(j != 0) printf(", ");
      printf("%d",tree[i].c[j]);
    }
    printf("]\n");
  }
  
  return;
}

int depth(node* tree,int c,int d){
  if(tree[c].parent == NIL) return d;
  else{
    d++;
    return depth(tree,tree[c].parent,d);
  }
}
