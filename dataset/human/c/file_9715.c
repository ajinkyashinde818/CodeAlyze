#include<stdio.h>

#define Max 100000
#define NIL -1

typedef struct Node{
  int p, l, r;
}Node;

Node T[Max];
int n, D[Max];

void print(int u){
  int i, c;

  printf("node %d: parent = %d, depth = %d, ", u, T[u].p, D[u]);

  if(T[u].p == NIL) printf("root, [");
  else if(T[u].l == NIL) printf("leaf, [");
  else printf("internal node, [");

  c = T[u].l;
  
  for(i = 0 ; c != NIL ; i++){  
    if(i) printf(", ");
    printf("%d", c);
    c = T[c].r;
  }
  printf("]\n");
}

int rec(int u, int p){
  D[u] = p;

  if(T[u].r != NIL) rec(T[u].r, p);
  if(T[u].l != NIL) rec(T[u].l, p + 1);
}

int main(){
  int i, j, d, v, c, l, r;

  scanf("%d", &n);

  for(i = 0 ; i < n ; i++){
    T[i].p = T[i].l = T[i].r = NIL;
  }

  for(i = 0 ; i < n ; i++){
    scanf("%d %d", &v, &d);
    for(j = 0 ; j < d ; j++){
      scanf("%d", &c);
      if(j == 0) T[v].l = c;
      else T[l].r = c;
      l = c;
      T[c].p = v;
    }
  }

  for(i = 0 ; i < n ; i++){
    if(T[i].p == NIL) r = i;
  }

  rec(r, 0);

  for(i = 0 ; i < n ; i++) print(i);

  return 0;
}
