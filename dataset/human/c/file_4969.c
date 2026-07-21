#include <stdio.h>

typedef struct Node{

  int parent;
  int left;
  int right;
}Node;

#define NIL -1

#define nil -1

#define Nil -1

#define MAX 10000

Node tree[MAX];

int n, depth[MAX], height[MAX];

int kyoudai(int u){

  if(tree[u].parent==NIL) return NIL;
  if(tree[tree[u].parent].left!=u && tree[tree[u].parent].left!=NIL){

    return tree[tree[u].parent].left;
  }
  if(tree[tree[u].parent].right!=u && tree[tree[u].parent].right!=NIL){

    return tree[tree[u].parent].right;
  }
 
    
  return NIL;
  
}

int takasa(int root){

  int h1=0, h2=0;
  if(tree[root].left!=NIL){
    
    h1=takasa(tree[root].left)+1;
  }
  if(tree[root].right!=NIL){
    
    h2=takasa(tree[root].right)+1;
  }

  if(h1>h2) height[root]=h1;
  else height[root]=h2;

  return height[root];
}

  
int horu(int root, int d){

  if(root==NIL){
    
    return NULL;
  }
  depth[root]=d;
  
  if(root!=NIL){
    
  horu(tree[root].left, d+1);
  horu(tree[root].right, d+1);
  }
  
}


int main(){

  int i, oya, hidari, migi, root=0;

  int degree=0;

  scanf("%d",&n);

  for(i=0;i<n;i++) tree[i].parent=tree[i].left=tree[i].right=-1;

  
  for(i=0;i<n;i++){

    scanf("%d",&oya);
    scanf("%d%d",&hidari,&migi);
    
    tree[oya].left=hidari;
    tree[oya].right=migi;

    if(hidari!=NIL) tree[hidari].parent=oya;
    if(migi!=NIL) tree[migi].parent=oya;
   
  }

  for(i=0;i<n;i++){

    if(tree[i].parent==NIL) root=i;
  }

  horu(root, 0);
  takasa(root);

  for(i=0;i<n;i++){

    degree=0;

    printf("node %d: parent = %d, sibling = %d, ",i, tree[i].parent,kyoudai(i));

    if(tree[i].left!=NIL) degree++;
    if(tree[i].right!=NIL)degree++;

    printf("degree = %d, ", degree);
    printf("depth = %d, ", depth[i]);
    printf("height = %d, ", height[i]);
  

    if(tree[i].parent==NIL) printf("root\n");
    else if(tree[i].left!=NIL||tree[i].right!=NIL) printf("internal node\n");
    else printf("leaf\n");

  }


  return 0;
  
}
