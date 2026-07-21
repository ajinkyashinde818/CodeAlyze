#include <stdio.h>

#define MAX 10000
#define NIL -1

struct Node{
  int p, l, r;
};
struct Node T[MAX];

int n, depth[MAX], height[MAX];

void Depth(int, int);
int Height(int);
int Sibling(int);
void print(int);

int main()
{
  int i;
  int id, left, right, tmp=0;

  scanf("%d", &n);
  
  for( i = 0 ; i < n ; i++ ) T[i].p = NIL;
  
  for( i = 0 ; i < n ; i++ ){
    scanf("%d%d%d", &id, &left, &right);
    T[id].l = left;
    T[id].r = right;
    if( left != NIL ) T[left].p = id;
    if( right != NIL ) T[right].p = id;
  }

  for( i = 0 ; i < n ; i++ ) if( T[i].p == NIL ) tmp = i;

  Depth(tmp, 0);
  Height(tmp);

  for( i = 0 ; i < n ; i++ ) print(i);

  return 0;
}

void Depth(int u, int p)
{
  if( u == NIL ) return;
  depth[u] = p;
  
  Depth(T[u].l, p+1);
  Depth(T[u].r, p+1);
}

int Height(int u)
{
  int h1=0, h2=0;
  
  if( T[u].l != NIL ) h1 = Height(T[u].l) + 1;
  if( T[u].r != NIL ) h2 = Height(T[u].r) + 1;

  if( h1 > h2 ) return height[u] = h1;
  else return height[u] = h2;
}

int Sibling(int u)
{
  if( T[u].p == NIL ) return NIL;
  if( T[T[u].p].l != u && T[T[u].p].l != NIL ) return T[T[u].p].l;
  if( T[T[u].p].r != u && T[T[u].p].r != NIL ) return T[T[u].p].r;
  return NIL;
}

void print(int node)
{
  int count=0;

  printf("node %d: parent = %d, sibling = %d, ", node, T[node].p, Sibling(node));

  if( T[node].l != NIL ) count++;
  if( T[node].r != NIL ) count++;
  
  printf("degree = %d, depth = %d, height = %d, ", count, depth[node], height[node]);

  if( T[node].p == NIL ) printf("root\n");
  else if( T[node].l == NIL && T[node].r == NIL ) printf("leaf\n");
  else printf("internal node\n");
}
