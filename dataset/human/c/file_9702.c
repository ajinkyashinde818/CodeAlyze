#include <stdio.h>
#define N 100000
#define NIL -1

typedef struct{int p, l, r;}Tree;

Tree t[N];
int n, d[N], k[N];

int Depth(int x, int p)
{
  d[x] = p;
  if(t[x].r != NIL) Depth(t[x].r, p);
  if(t[x].l != NIL) Depth(t[x].l, p+1);
}

void print(int x)
{
  int i, j, c;
  printf("node %d: parent = %d, depth = %d, ", x, t[x].p, d[x]);

  if(t[x].p == NIL) printf("root, ");
  else if(t[x].l == NIL) printf("leaf, ");
  else printf("internal node, ");

  printf("[");
  for(i = 0, c = t[x].l; c != NIL; i++, c = t[c].r){
    if(i > 0) printf(", ");
    printf("%d", c);
  }
  printf("]\n");
}

int main()
{
  int i, j, c, id, d, l, r;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    t[i].p = NIL;
    t[i].l = NIL;
    t[i].r = NIL;
  }
  
  for(i = 0; i < n; i++){
    scanf("%d%d", &id, &k[i]);
    for(j = 0; j < k[i]; j++){
      scanf("%d", &c);
      if(j == 0) t[id].l = c;
      else t[l].r = c;
      l = c;
      t[c].p = id;
    }
  }

  for(i = 0; i < n; i++){
    if(t[i].p == NIL) r =i;
  }
  Depth(r, 0);
  for(i = 0; i < n; i++) print(i);

  return 0;
}
