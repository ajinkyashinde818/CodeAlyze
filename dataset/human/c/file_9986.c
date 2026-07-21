#include<stdio.h>
#define MAX 100005
#define NIL -1
 
typedef struct{
  int parent;
  int left;
  int right;
}Node;
 
Node Tree[MAX];
int n, Depth[MAX];
 
int getDepth(int);
void print(int);
 
int child[MAX];
 
int main(){
  int i, j;
  int degree,number;
 
  scanf("%d", &n);
 
  for ( i = 0; i < n; i++ ) {
    Tree[i].parent = NIL;
    Tree[i].left = NIL;
    Tree[i].right = NIL;
  }
 
  for ( i = 0; i < n; i++ ){
    scanf("%d %d", &number, &degree);
    for ( j = 0; j < degree; j++ ){
      scanf("%d", &child[j]);
 
      Tree[child[j]].parent = number;
       
      if(j == 0)
    Tree[number].left = child[0];
       
      else
    Tree[child[j - 1]].right = child[j];
    }
  }
   
  for ( i = 0; i < n; i++ )
    Depth[i] = getDepth(i);
   
  for ( i = 0; i < n; i++ )
    print(i);
   
  return 0;
}
 
int getDepth(int u){
  int d = 0;
 
  while(Tree[u].parent >= 0){
    u = Tree[u].parent;
    d++;
  }
 
  return d;
}
 
void print(int u){
 
  int i, cnt = 0;
 
  printf("node %d: parent = %d, depth = %d, ",u,Tree[u].parent,Depth[u]);
 
  if(Tree[u].parent == NIL)
    printf("root, [");
 
  else if(Tree[u].left == NIL)
    printf("leaf, [");
 
  else
    printf("internal node, [");
 
  u = Tree[u].left;
  while(u != NIL){
    if(cnt == 0)
      printf("%d",u); 
 
    else
      printf(", %d",u);
   
    u = Tree[u].right;
    cnt++;
 
     
  
 }
 
 
    printf("]\n");
 
}
