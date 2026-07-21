#include <stdio.h>
#define MAX 30
#define NIL -1

typedef struct Node{
  int parent;
  int left;
  int right;
}Node;

typedef struct node{
  int sibling;
  int degree;
  int depth;
  int height;
}Depth;

Node gNode[MAX];
Depth gDepth[MAX];

void print(int, int);
void rec(int, int);
void height(int, int);

int main(){
  int n,i,j,nodeP,left,right,root;

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    gNode[i].parent = NIL;
    gNode[i].left = NIL;
    gNode[i].right = NIL;
    gDepth[i].height = NIL;
  }

  for(i = 0; i < n; i++){
    scanf("%d%d%d",&nodeP,&left,&right);
    gNode[nodeP].left = left;
    gNode[nodeP].right = right;
    if(left != NIL) gNode[left].parent = nodeP;
    if(right != NIL) gNode[right].parent = nodeP;
  }
   for(i = 0; i < n; i++){
    if(gNode[i].parent == NIL){
      root = i;
    }
  }
   gDepth[root].sibling = NIL;
   
   for(i = 0; i < n; i++){
     if(i != root){
       if(i != gNode[gNode[i].parent].left) gDepth[i].sibling = gNode[gNode[i].parent].left;
       else if(i != gNode[gNode[i].parent].right) gDepth[i].sibling = gNode[gNode[i].parent].right;
     }
     if(gNode[i].right != NIL && gNode[i].left != NIL) gDepth[i].degree = 2;
     else if(gNode[i].right != NIL || gNode[i].left != NIL) gDepth[i].degree = 1;
     else{
       gDepth[i].degree = 0;
       gDepth[i].height = 0;
     }
     if(gDepth[i].height == 0) height(i,0);
   }


   rec(root,0);

   for(i = 0; i < n; i++){
     print(i,n);
  }
  return 0;

}

void rec(int node, int depth){
  gDepth[node].depth = depth;
  if(gNode[node].left != NIL) rec(gNode[node].left,depth+1);
  if(gNode[node].right != NIL) rec(gNode[node].right,depth+1);
}

void height(int node, int hei){
  if(gDepth[node].height < hei) gDepth[node].height = hei;
  if(gNode[node].parent != NIL) height(gNode[node].parent,hei+1);
}

void print(int node, int n){
  printf("node %d: parent = %d, sibling = %d, ",node,gNode[node].parent,gDepth[node].sibling);
  printf("degree = %d, depth = %d, height = %d, ",gDepth[node].degree,gDepth[node].depth,gDepth[node].height);
  if(gNode[node].parent == NIL) printf("root\n");
  else if(gNode[node].left == NIL && gNode[node].right == NIL) printf("leaf\n");
  else printf("internal node\n");
}
