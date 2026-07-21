#include <stdio.h>
#define MAX 100005
#define NIL -1

typedef struct Node{
  int parent;
  int child;
  int sibling;
}Node;

Node gNode[MAX];
int gDepth[MAX];

void print(int);
void rec(int, int);

int main(){
  int i,j,nodeN,nodeI,node,child,root,n;

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    gNode[i].parent = NIL;
    gNode[i].child = NIL;
    gNode[i].sibling = NIL;
  }

  for(i = 0; i < n; i++){
    scanf("%d%d",&nodeI,&nodeN);
    for(j = 0; j < nodeN; j++){
      scanf("%d",&node);
      if(j == 0){
	gNode[nodeI].child = node;
      }
      else{
	gNode[child].sibling = node;
      }
      child = node;
      gNode[node].parent = nodeI;
    }
  }

  for(i = 0; i < n; i++){
    if(gNode[i].parent == NIL){
      root = i;
    }
  }

  rec(root,0);

  for(i = 0; i < n; i++){
    print(i);
  }
  return 0;
}

void print(int node){
  int i,child;
  
  printf("node %d: ",node);
  printf("parent = %d, ",gNode[node].parent);
  printf("depth = %d, ",gDepth[node]);

  if(gNode[node].parent == NIL) printf("root, ");
  else if(gNode[node].child == NIL) printf("leaf, ");
  else printf("internal node, ");

  printf("[");

  for(i = 0,child = gNode[node].child; child != NIL; i++,child = gNode[child].sibling){
    if(i) printf(", ");
    printf("%d",child);
  }
  
  printf("]\n");
}

void rec(int node, int parent){
  gDepth[node] = parent;
  if(gNode[node].sibling != NIL){
    rec(gNode[node].sibling,parent);
  }
  if(gNode[node].child != NIL){
    rec(gNode[node].child,parent+1);
  }
}
