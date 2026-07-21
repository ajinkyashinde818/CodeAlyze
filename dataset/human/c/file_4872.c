#include<stdio.h>
#include<stdlib.h>
#define MAX 25
#define NIL -1
struct Node_struct{int p,right,left,s;};
typedef struct Node_struct Node;
Node T[MAX];
int D[MAX],H[MAX];

int getSibling(int u){
  if(T[u].p == NIL){
    return NIL;
  }
  if(T[T[u].p].left != u && T[T[u].p].left != NIL){
    return T[T[u].p].left;
  }
  if(T[T[u].p].right != u && T[T[u].p].right != NIL){
    return T[T[u].p].right;
  }
  return NIL;
}

int setHeight(int u){
  int h1=0,h2=0;
  if(T[u].left != NIL){
    h1 = setHeight(T[u].left) + 1;
  }
  if(T[u].right != NIL){
    h2 = setHeight(T[u].right) +1;
  }
  if(h1>h2){
    H[u]=h1;
  }else{
    H[u]=h2;
  }
  return H[u]; 
}


void calcDepth(int u, int p){
  D[u] = p;
  if(T[u].left!=NIL) calcDepth(T[u].left,p+1);
  if(T[u].right!=NIL) calcDepth(T[u].right,p+1);
}

void print(int u){
  int deg=0;
  printf("node %d: parent = %d, ", u, T[u].p);
  printf("sibling = %d, ",getSibling(u));
  if(T[u].left != NIL){
    deg++;
  }
  if(T[u].right != NIL){
    deg++;
  }
  printf("degree = %d, ",deg);
  printf("depth = %d, ",D[u]);
  printf("height = %d, ",setHeight(u));
  if(T[u].p==NIL) printf("root");
  else if(T[u].left==T[u].right && T[u].left==NIL) printf("leaf");
  else printf("internal node");
  printf("\n");
  
}

int main(){
  int i;
  int n;
  int id;
  int root = NIL;
  scanf("%d", &n);
  for(i=0; i<n; i++) T[i].p = T[i].right = T[i].left = NIL;
  for(i=0; i<n; i++){
    if(i==0){
      T[0].p=NIL;
    }
    scanf("%d", &id);
    scanf("%d %d", &T[id].left,&T[id].right);
    T[T[id].right].p = T[T[id].left].p = id;
    T[T[id].right].s = T[id].right;
    T[T[id].left].s = T[id].left;
  }
  //根を求める (find the root)
  for(i=0; i<n; i++){
    if(T[i].p == -1) root = i;
  }
  //それぞれのノードの深さを求める (find depth of each node)
  calcDepth(root, 0);  
  //出力 (output)
  for(i=0; i<n; i++) print(i);
  
  return 0;
}
