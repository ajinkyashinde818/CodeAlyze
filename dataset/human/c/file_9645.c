#include<stdio.h>
#define MAX 100005
#define NIL -1
struct Node_struct{int p, l, r;};
typedef struct Node_struct Node;
Node T[MAX];
int n, D[MAX];

void print(int u){
  int i, c;
  printf("node %d: parent = %d, depth = %d, ", u, T[u].p, D[u]);
  if(T[u].p == NIL) printf("root, ");
  else if(T[u].l == NIL) printf("leaf, ");
  else printf("internal node, ");
  printf("[");
  for (i =0, c = T[u].l; c != NIL; i++, c = T[c].r){
    if(i) printf(", ");
    printf("%d", c);
  }
  printf("]\n");
}

void rec(int u, int p){
  D[u] = p;
  if(T[u].l != NIL) rec(T[u].l, p + 1);
  if(T[u].r != -1) rec(T[u].r, p);
}

int main(){
  int i, j, k;
  int N;
  int id, sib, child;
  int root = NIL;
  scanf("%d", &N);
  for(i=0;i<N;i++) T[i].p = T[i].l = T[i].r = NIL;
  
  for(i=0; i<N; i++){
    scanf("%d %d", &id, &k);
    for(j =0, sib= NIL; j<k; j++){
      scanf("%d", &child);
      T[child].p = id;
      if(j == 0) T[id].l = child;
      else T[sib].r = child;
      sib = child;
    }
  }

  for(i=0; i<N; i++){
    if(T[i].p == -1) root = i;
  }
  rec(root, 0);
  for(i=0; i<N; i++) print(i);
  
  return 0;
}
