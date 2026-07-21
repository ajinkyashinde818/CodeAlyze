#include<stdio.h>
#define MAX 100005
#define NIL -1

struct Node{int pa, le, ri;};
struct Node T[MAX];
int n, H, D[MAX];

int getDepth(int u);

void print(int u);

int main(){
  int i, j, d, v, c, l;
  
  scanf("%d", &n);
  for ( i = 0; i < n; i++ ) T[i].pa = T[i].le = T[i].ri = NIL;

  for ( i = 0; i < n; i++ ){
    scanf("%d %d", &v, &d);
    for ( j = 0; j < d; j++ ){
      scanf("%d", &c);
      if ( j == 0 ) T[v].le = c;
      else T[l].ri = c;
      l = c;
      T[c].pa = v;
    }
  }
  
  H = 0;
  for ( i = 0; i < n; i++ ){
    D[i] = getDepth(i);
    if ( D[i] > H ) H = D[i];
  }

  for ( i = 0; i < n; i++ ) print(i);
  return 0;
}

int getDepth(int u){
  int d = 0;
  for(; T[u].pa != NIL ;d++) u = T[u].pa;
  return d;
}

void print(int u){
  int i, c;
  printf("node %d: ", u);
  printf("parent = %d, ", T[u].pa);
  printf("depth = %d, ", D[u]);

  if ( T[u].pa == NIL ) printf("root, ");
  else if ( T[u].le == NIL ) printf("leaf, ");
  else printf("internal node, ");

  printf("[");
  for(i = 0, c = T[u].le; c != NIL; i++, c = T[c].ri){
    if (i) printf(", ");
    printf("%d", c);
  }
  printf("]\n");
}
