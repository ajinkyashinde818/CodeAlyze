#include <stdio.h>
#include <stdlib.h>
#define NIL -1

typedef struct node{
  int left;
  int right;
  int parent;
}node;

int getSibling(int);
int getDegree(int);
int getDepth(int);
int getHeight(int);
void printTree(void);

node *tree;
int n;

int main(){
  int id,left,right,i;
  
  scanf("%d",&n);
  tree = (node *)malloc(sizeof(node)*n);
  for(i=0;i<n;i++){
    tree[i].parent = NIL;
  }
  for(i=0;i<n;i++){
    scanf("%d %d %d",&id,&left,&right);
    
    tree[id].left = left;
    
    tree[id].right = right;
    
    tree[tree[id].left].parent = id;
    
    tree[tree[id].right].parent = id;
  }

  printTree();

  return 0;
}

int getSibling(int c){
  int left,right;
  if(tree[c].parent!=-1){
    left = tree[tree[c].parent].left;
    right = tree[tree[c].parent].right;

    if(left!=-1&&c!=left) return left;
    else if(right!=-1&&c!=right) return right;
  }
  return -1;
}

int getDegree(int c){
  int d=0;
  if(tree[c].left!=-1) d++;
  if(tree[c].right!=-1) d++;
 
  return d;
}

int getDepth(int c){
  int d=0;
  while(tree[c].parent!=-1){
    c=tree[c].parent;
    d++;
  }
  return d;
}

int getHeight(int c){
  int d=0;
  if(tree[c].left==-1&&tree[c].right==-1) return 0;
  if(tree[c].left==-1) return getHeight(tree[c].right)+1;
  if(tree[c].right==-1) return getHeight(tree[c].left)+1;
  if(getHeight(tree[c].left)<getHeight(tree[c].right))
    return getHeight(tree[c].right)+1;
  else return getHeight(tree[c].left)+1;
  return d;
}

void printTree(){
  int i,deep,h;
  for(i=0;i<n;i++){
    deep=getDepth(i);
    h=getHeight(i);
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,tree[i].parent,getSibling(i),getDegree(i),deep,h);
    if(deep==0) printf("root\n");
    else if(h==0) printf("leaf\n");
    else printf("internal node\n");
  }

  return;
}
