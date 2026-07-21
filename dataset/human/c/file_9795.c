#include <stdio.h>

#define MAX 100005
#define NIL -1

struct Node{
  int p, l, r;
};
 
struct Node T[MAX];
int n, D[MAX];
 
int getD(int);
void print(int);
 
int dik[MAX];

int main(void){
  int i, j;
  int deg, ver;
  scanf("%d", &n);
  for ( i = 0; i < n; i++ ) {
    T[i].p = NIL;
    T[i].l = NIL;
    T[i].r = NIL;
  }
  for ( i = 0; i < n; i++ ){
    scanf("%d %d", &ver, &deg);
    for ( j = 0; j < deg; j++ ){
      scanf("%d", &dik[j]);
      T[dik[j]].p = ver;
      if(j == 0)
        T[ver].l = dik[0];
      else
        T[dik[j - 1]].r = dik[j];
    }
  }
  for ( i = 0; i < n; i++ )
    D[i] = getD(i);
  for ( i = 0; i < n; i++ )
    print(i);
  return 0;
}
 
int getD(int u){
  int d = 0;
  while(T[u].p >= 0){
    u = T[u].p;
    d++;
  }
  return d;
}
 
void print(int u){
  int i, cnt = 0;
  printf("node %d: parent = %d, depth = %d, ",u,T[u].p,D[u]);
  if(T[u].p == NIL)
    printf("root, [");
  else if(T[u].l == NIL)
    printf("leaf, [");
  else
    printf("internal node, [");
  u = T[u].l;
  while(u != NIL){
    if(cnt == 0)
      printf("%d",u); 
    else
      printf(", %d",u); 
    u = T[u].r;
    cnt++;
  } 
 
    printf("]\n");
}
