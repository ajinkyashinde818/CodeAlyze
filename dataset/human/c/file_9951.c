#include <stdio.h>
#define MAX 100000

struct node{
  //int p, d, c[10], t, k; //????????????,???????????±???,???????????????,type,?¬???°
  int p, l, r;
};
struct node T[MAX];
int n, D[MAX];

void print(int u){
  int i = 0, c;
  printf("node %d: parent = %d, depth = %d, ", u, T[u].p, D[u]);

  if(T[u].p == -1) printf("root, [");
  else if(T[u].l == -1) printf("leaf, [");
  else printf("internal node, [");

  for(i = 0, c = T[u].l; c != -1; i++, c = T[c].r){
    if(i) printf(", ");
    printf("%d", c);
  }
  printf("]\n");
}

int rec(int u, int p){
  D[u] = p;
  if(T[u].r != -1) rec(T[u].r, p);
  if(T[u].l != -1) rec(T[u].l, p + 1);
}

int main()
{
  /*  node T[MAX];
  int i = 0, j, t = 0, l;
  int n, id; //?????°,???????????????
  char type[4][] = {root???internal node???leaf}
  */
  int i, j, k, id, c, l, r;

  scanf("%d", &n);
  for(i = 0; i < n; i++) T[i].p = T[i].l = T[i].r = -1;
  for(i = 0; i < n; i++){
    scanf("%d %d", &id, &k);
    for(j = 0; j < k; j++){
      scanf("%d", &c);
      if(j == 0) T[id].l = c;
      else T[l].r = c;
      l = c;
      T[c].p = id;
    }
  }
  for(i = 0; i < n; i++){
    if(T[i].p == -1) r = i;
  }
  rec(r,0);
  for(i = 0; i < n; i++) print(i);

  return 0;
}
