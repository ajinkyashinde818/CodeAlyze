#include<stdio.h>
 
#define MAX 100005
#define NIL -1
 
struct Node{
  int parent;
  int left;
  int right;
};
 
struct Node N[MAX];
 
int n, H, D[MAX];
 
int getDepth(int u){
  int d = 0;
  while(N[u].parent >= 0){
    u = N[u].parent;
    d++;
  }
   
  return d;
}
 
void printTree(int u){
  int t;
 
  if(N[u].parent == NIL) printf("node %d: parent = %d, depth = %d, root, ", u, N[u].parent, D[u]);
   
  else if(N[u].left == NIL) printf("node %d: parent = %d, depth = %d, leaf, ", u, N[u].parent, D[u]);
   
  else printf("node %d: parent = %d, depth = %d, internal node, ", u, N[u].parent, D[u]);
     
  printf("[");
 
  t = u;
 
  if(N[t].left != NIL){
    printf("%d", N[t].left);
 
    if(N[N[t].left].right == NIL) printf("]\n");
 
    else printf(",");
 
    t = N[t].left;
 
    while(N[t].right != NIL){
      printf(" %d",N[t].right);
       
      if(N[N[t].right].right == NIL) printf("]\n");
 
      else printf(",");
 
      t = N[t].right;
    }
  }
   
  else printf("]\n");
}
 
int main(){
  int i, j, d, v, c, l, r;
   
  scanf("%d", &n);
   
  for(i = 0; i < n; i++){
    N[i].parent = N[i].left = N[i].right = NIL;
  }
   
  for ( i = 0; i < n; i++ ){
    scanf("%d %d", &v, &d);
 
    for(j = 0; j < d; j++){
      scanf("%d", &c);
 
      N[c].parent = v;
       
      if(j == 0) N[v].left = c;
       
      else if (j >= 1) N[r].right = c;
      r = c;
    }
  }
   
  for(i = 0; i < n; i++) D[i] = getDepth(i);
   
  for(i = 0; i < n; i++) printTree(i);
  return 0;
}
