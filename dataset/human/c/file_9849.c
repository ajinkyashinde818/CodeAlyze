#include<stdio.h>
#define MAX 100000

struct Node{ int p, l, r;};
struct Node tree[MAX];
int n,depth[MAX];

int getDepth(int u){
  int d = 0;
  for(; tree[u].p!= -1 ;d++)
   u = tree[u].p;

  return d;
}

void print(int x){
  int i, count;
  printf("node %d: ", x);
  printf("parent = %d, ", tree[x].p);
  printf("depth = %d, ", depth[x]);

  if ( tree[x].p == -1 ) 
    printf("root, ");
  else if ( tree[x].l == -1 )
    printf("leaf, ");
  else
    printf("internal node, ");

  printf("[");
  for(i = 0, count = tree[x].l; count != -1; i++, count = tree[count].r){
    if (i!=0) 
        printf(", ");

    printf("%d", count);
  }
  printf("]\n");
}

main(){
  int i, j,k=0;
  int d, v, x, l;
  scanf("%d", &n);
  for ( i = 0; i < n; i++ ) 
  tree[i].p = tree[i].l = tree[i].r = -1;

  for ( i = 0; i < n; i++ ){
    scanf("%d %d", &v, &d);
    for ( j = 0; j < d; j++ ){
      scanf("%d", &x);
      if ( j == 0 ) 
        tree[v].l = x;
      else
        tree[l].r = x;

      l = x;
      tree[x].p = v;
    }
  }
  for ( i = 0; i < n; i++ ){
    depth[i] = getDepth(i);
    if ( depth[i]>k ) 
        k = depth[i];
  }

  for ( i = 0; i < n; i++ ) print(i);
  return 0;
}
