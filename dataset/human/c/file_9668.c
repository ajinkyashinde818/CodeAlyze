#include<stdio.h>

#define MAX 100005
#define NIL -1
 
typedef struct{
  int parent,left,right;
 }Node;
 
Node T[MAX];
 int n, D[MAX];
 int getDepth(int);
void print(int);

  int child[MAX];
  int main(void){
  int i, j;
  int degree,vertex;
 
  scanf("%d", &n);
 
  for (i = 0;i < n;i++ ) {
    T[i].parent = NIL;
    T[i].left = NIL;
    T[i].right = NIL;
  }
 
  for (i = 0;i < n;i++ ){
    scanf("%d %d", &vertex, &degree);
    for (j = 0;j < degree;j++ ){
      scanf("%d", &child[j]);
      T[child[j]].parent = vertex;
     if(j == 0) T[vertex].left = child[0];
      else
    T[child[j - 1]].right = child[j];
    }
  }
   
  for ( i = 0; i < n; i++ )
    D[i] = getDepth(i);
   
  for ( i = 0; i < n; i++ )
    print(i);
   
  return 0;
}

  int getDepth(int u){
  int d = 0;
 
  while(T[u].parent >= 0){
    u = T[u].parent;
    d++;
  }
   return d;
}
 
void print(int u){
 
  int i, cnt = 0;
 
  printf("node %d: parent = %d, depth = %d, ",u,T[u].parent,D[u]);
 
  if(T[u].parent == NIL)
    printf("root, [");
 
  else if(T[u].left == NIL)
    printf("leaf, [");
 
  else
    printf("internal node, [");
 
  u = T[u].left;
  while(u != NIL){
    if(cnt == 0)
      printf("%d",u); 
 
    else
      printf(", %d",u);
   
    u = T[u].right;
    cnt++;
 }
     printf("]\n");
 
}
