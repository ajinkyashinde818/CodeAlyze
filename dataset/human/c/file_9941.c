#include<stdio.h>
#define N 100001
#define NIL -1

typedef struct {
  int parent, left, right;
}Node;

Node Tree[N]; 
void print(int);
int Depth[N];



int main(VOID){
  int i, j, n, cc, child[N], node;
  scanf("%d", &n);
  
  for ( i = 0; i < n; i++ ) {
    Tree[i].parent = NIL;
    Tree[i].left = NIL;
    Tree[i].right = NIL;
  }
  
  

  for(i=0; i < n; i++ ){
    scanf("%d %d", &node, &cc);
    for(j=0; j < cc; j++){
      scanf("%d", &child[j]);
      
      Tree[child[j]].parent = node;
      if(j == 0) Tree[node].left = child[0];
      else Tree[child[j-1]].right = child[j]; 
    }
  }
  
  for(i=0; i<n;i++) Depth[i] = getDepth(i);
  for ( i = 0; i < n; i++ ) print(i);
  
  return 0;
}





int getDepth(int in){
  int d=0;
  
  while(Tree[in].parent >= 0){
    in = Tree[in].parent;  
    d++;
  }
  
  return d;
}


void print(int node){
  int i, count=0;
  
  printf("node %d: parent = %d, depth = %d, ",node ,Tree[node].parent, Depth[node]);
  
  if(Tree[node].parent == NIL)
    printf("root, [");
  
  else if(Tree[node].left == NIL)
    printf("leaf, [");
  
  else
    printf("internal node, [");
  
  node = Tree[node].left;
  while(node != NIL){
    if(count==0) printf("%d", node);
    else printf(", %d", node);
    
    node = Tree[node].right;
    count++;
    
  }
  
  
  printf("]\n");
  
}
