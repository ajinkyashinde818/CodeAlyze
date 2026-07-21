#include <stdio.h>

#define MAX 1000000
#define NIL -1

struct Node{int p, l, r; };

struct Node T[MAX];
int n, D[MAX];

void print(int u);
int rec(int u, int p);

int main(){
  int i, j, k, l, d, s, c, r;

  scanf("%d", &n);
  for(i=0; i<n; i++){
    T[i].p=NIL;
    T[i].l=NIL;
    T[i].r=NIL;
}

  for(i=0; i<n; i++){
    scanf("%d%d", &s, &d);
    for(j=0; j<d; j++){
      scanf("%d", &c);
      if(j==0) T[s].l=c;
      else T[l].r =c;
      l=c;
      T[c].p=s;
    }
  }
  for(i=0; i<n; i++){
    if(T[i].p==NIL) r=i;
  }
  rec(r, 0);
  for(i=0; i<n; i++) print(i);
  return 0;
}

void print(int u){
  int j, c;
  printf("node %d: parent = %d, depth = %d, ", u, T[u].p, D[u]);
  if(T[u].p==NIL)         printf("root, ");
  else if(T[u].l==NIL)    printf("leaf, ");
  else                    printf("internal node, ");

  printf("[");
  for(j=0, c=T[u].l; c!=NIL; j++, c=T[c].r){
    if(j)       printf(", ");
    printf("%d", c);
}
  printf("]\n");
}
int rec(int u, int p){
  D[u]=p;
  if(T[u].r!=NIL) rec(T[u].r, p);
  if(T[u].l!=NIL) rec(T[u].l, p+1);
}
