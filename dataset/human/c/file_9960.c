#include <stdio.h>

#define MAX 100000 
#define NIL -1

struct Node{ 
  int p, l, r;
};
struct Node type[MAX];

void print(int);
int rec(int, int);

int n, depth[MAX];

int main()
{
  int id, k, c;
  int i, j, tmp, tmp1;

  scanf("%d", &n);

  for( i = 0 ; i < n ; i++ ) type[i].p=type[i].l=type[i].r=NIL;

  for( i = 0 ; i < n ; i++ ){
    scanf("%d%d", &id, &k);
    for( j = 0 ; j < k ; j++ ){
      scanf("%d", &c);
      if( j == 0 ) type[id].l = c;
      else type[tmp].r = c;
      tmp = c;
      type[c].p = id;
    }
  }
  
  for( i = 0 ; i < n ; i++ ){
    if( type[i].p == NIL ) tmp1 = i;
  }

  rec(tmp1, 0);

  for( i = 0 ; i < n ; i++ ) print(i);

  return 0;
}

void print(int node)
{
  int i, c;

  printf("node %d: parent = %d, depth = %d, ", node, type[node].p, depth[node]);
  
  if( type[node].p == NIL ) printf("root, ");
  else if( type[node].l == NIL ) printf("leaf, ");
  else printf("internal node, ");

  printf("[");

  for( i = 0 , c = type[node].l ; c != NIL ; i++, c = type[c].r){
    if( i ) printf(", ");
    printf("%d", c);
  }
  printf("]\n");
}

int rec(int u, int p)
{
  depth[u] = p;
  
  if( type[u].r != NIL ) rec(type[u].r, p);
  if( type[u].l != NIL ) rec(type[u].l, p+1);
}
