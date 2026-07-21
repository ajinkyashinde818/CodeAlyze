#include<stdio.h>
#define M 100005
#define N -1

struct Node{ int p, l, r;};
struct Node t[M];
int n, H, d[M];

int Depth(int u){
  int x = 0;
  for(; t[u].p != N ;x++) u = t[u].p;
  return x;
}

void print(int u){
  int i, c;
  printf("node %d: ", u);
  printf("parent = %d, ", t[u].p);
  printf("depth = %d, ", d[u]);

  if ( t[u].p == N ) printf("root, ");
  else if ( t[u].l == N ) printf("leaf, ");
  else printf("internal node, ");

  printf("[");
  for(i = 0, c = t[u].l; c != N; i++, c = t[c].r){
    if (i) printf(", ");
    printf("%d", c);
  }
  printf("]\n");
}

main(){
  int i, j, s, v, c, l;
  scanf("%d", &n);
  for ( i = 0; i < n; i++ ) t[i].p = t[i].l = t[i].r = N;

  for ( i = 0; i < n; i++ ){
    scanf("%d %d", &v, &s);
    for ( j = 0; j < s; j++ ){
      scanf("%d", &c);
      if ( j == 0 ) t[v].l = c;
      else t[l].r = c;
      l = c;
      t[c].p = v;
    }
  }

  H = 0;
  for ( i = 0; i < n; i++ ){
    d[i] = Depth(i);
    if ( d[i] > H ) H = d[i];
  }

  for ( i = 0; i < n; i++ ) print(i);
  return 0;
}
