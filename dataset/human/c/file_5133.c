#include<stdio.h>
#define MAX 100005
#define NIL -1
struct Node_struct{int p, l, r;};
typedef struct Node_struct Node;
Node T[MAX];
int D[MAX];
int H[MAX];
int deg[MAX];
int maxDepth = 0;

void print(int u, int root){
  int s;
  printf("node %d: parent = %d, ", u, T[u].p);
  if(u == root) s = -1;
  else if(T[T[u].p].l == u) s = T[T[u].p].r;
  else if(T[T[u].p].r == u) s = T[T[u].p].l;
  printf("sibling = %d, degree = %d, depth = %d, height = %d, ", s, deg[u], D[u], H[u]);
  
  if(T[u].p == NIL) printf("root\n");
  else if(T[u].l == NIL && T[u].r == NIL) printf("leaf\n");
  else printf("internal node\n");
}

void calcDepth(int u, int p){
  D[u] = p;
  if(T[u].l != NIL) calcDepth(T[u].l, p+1);
  if(T[u].r != NIL) calcDepth(T[u].r, p+1);
}

int calcHeight(int u){
  int h1 = 0, h2 = 0;
  if(T[u].l != NIL) h1 = calcHeight(T[u].l)+1;
  if(T[u].r != NIL) h2 = calcHeight(T[u].r)+1;
  return H[u] = (h1 > h2 ? h1: h2);
}

void calcDeg(int u){
  deg[u] = 0;
  if(T[u].l != NIL){
    deg[u]++;
    calcDeg(T[u].l);
  }
  if(T[u].r != NIL){
    deg[u]++;
    calcDeg(T[u].r);
  }
}

int main(){
  int i, id;
  int n;
  int root = NIL;
  scanf("%d", &n);
  for(i=0; i<n; i++) T[i].p = T[i].l = T[i].r = NIL;

  for(i=0; i<n; i++){
    scanf("%d", &id);
    scanf("%d %d", &T[id].l, &T[id].r);
    T[T[id].l].p = id;
    T[T[id].r].p = id;
  }

  for(i=0; i<n; i++){
    if(T[i].p == -1) root = i;
  }

  calcDepth(root, 0);

  for(i = 0; i < n; i++){
    if(maxDepth < D[i]) maxDepth = D[i];
  }

  calcHeight(root);

  calcDeg(root);
  
  for(i=0; i<n; i++) print(i, root);

  return 0;
}
