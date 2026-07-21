#include<stdio.h>
#define MAX 25
#define NIL -1
struct Node_struct{int p, s, d, l, r;}; /*p: 親(parent), l: 左の子(left child), r:右の子(right child)*/
typedef struct Node_struct Node;
Node T[MAX];
int D[MAX];
int H[MAX];

void print(int u){
 
  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d", u, T[u].p, T[u].s, T[u].d, D[u], H[u]);


  
  if(T[u].p == NIL) printf(", root");
  else if(T[u].d == 0) printf(", leaf");
  else printf(", internal node");
  
  
  
  printf("\n");
  
}

void calcDepth(int u, int p){
  D[u] = p;
  if(T[u].l != NIL) calcDepth(T[u].l,p+1);
  if(T[u].r != NIL) calcDepth(T[u].r,p+1);
}

void calcHeight(int u, int p){
  
  if(T[u].d == 0) H[u] = 0;
  else{
  
  if(T[u].l != NIL) calcHeight(T[u].l,p);
  if(T[u].r != NIL) calcHeight(T[u].r,p);

  H[u] = H[T[u].l]+1;
  
  if(H[T[u].l] < H[T[u].r]) H[u] = H[T[u].r]+1;
  }
}

     
int main(){
  int i, j;
  int n;
  int id, childr, childl;
  int root = NIL;
  scanf("%d", &n);
  for(i=0; i<n; i++) {
    T[i].p = T[i].s = T[i].l = T[i].r = NIL;
    T[i].d =0;
    H[i] = -1;
  }
  for(i=0; i<n; i++){
    scanf("%d %d %d", &id, &childr, &childl);
    if(childr != -1){
      T[id].r = childr;
      T[childr].p = id;
      T[id].d++;
      
    }
    if(childl != -1){
       T[id].l = childl;
      T[childl].p = id;
      T[id].d++;
    }
    if((childr != -1)&&(childl != -1)){
    T[childr].s = childl;
    T[childl].s = childr;
    }
    
  }
  

  //根を求める (find the root)
  for(i=0; i<n; i++){
    if(T[i].p == -1) root = i;
  }
  
  //それぞれのノードの深さを求める (find depth of each node)
  calcDepth(root, 0);

  //それぞれのノードの高さを求める
  calcHeight(root, 0);

  //出力 (output)
  for(i=0; i<n; i++) print(i);
  
  return 0;
}
