#include<stdio.h>
#define MAX 25
#define NIL -1
struct Node_struct{int p, l, r;}; /*p: 親(parent), l: 一番左の子(left child), r:右の兄弟(right sibling)*/
typedef struct Node_struct Node;
Node T[MAX];
int n,D[MAX],H[MAX];

int setHeight(int u){
  int h1 = 0,h2 = 0;
  if(T[u].l != NIL){
    h1 = setHeight(T[u].l) + 1;
  }
  if(T[u].r != NIL){
    h2 = setHeight(T[u].r) + 1;
  }
  if(h1 > h2){
    H[u] = h1;
  }
  else H[u] = h2; 
  return H[u];
}

int getSibling(int u){
  if(T[u].p == NIL) return NIL;
  if(T[T[u].p].l != u && T[T[u].p].l != NIL) return T[T[u].p].l;
  if(T[T[u].p].r != u && T[T[u].p].r != NIL) return T[T[u].p].r;

  return NIL;
}

void print(int u){
  int c = 0;
  printf("node %d: parent = %d, sibling = %d, ", u, T[u].p, getSibling(u));

  if(T[u].l != NIL) c++;
  if(T[u].r != NIL) c++;
  printf("degree = %d, ",c);
  printf("depth = %d, ",D[u]);
  printf("height = %d, ",H[u]);

  if(T[u].p == NIL){
    printf("root\n");
  }
  else if(T[u].l == NIL && T[u].r == NIL){
    printf("leaf\n");
  }
  else{
    printf("internal node\n");
  }
}

void calcDepth(int u, int p){
  if(u == NIL) return ;
  D[u] = p;
  if(T[u].r != NIL) calcDepth(T[u].r,p+1);
  if(T[u].l != NIL) calcDepth(T[u].l,p+1);
}

int main(){
  int i, j, k, l;
  int root = 0;
  scanf("%d", &n);
  
  for(i=0; i < n;i++)T[i].p = NIL;

  for(i=0; i < n;i++){
    scanf("%d %d %d", &j, &k, &l);
    T[j].l = k;
    T[j].r = l;
    if(k != NIL)T[k].p = j;
    if(l != NIL)T[l].p = j;
  }

  //根を求める (find the root)
  for(i=0; i < n;i++){
    if(T[i].p == NIL) root = i;
  }

  //それぞれのノードの深さを求める (find depth of each node)
  calcDepth(root, 0);
  setHeight(root);
//出力 (output)
  for(i=0; i < n;i++){
    print(i);
  }

  return 0;
}
