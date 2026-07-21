/******************/
/*  Binary Trees  */
/******************/
#include <stdio.h>
#define MAX 25
#define NIL -1

/* Struct Declaration */
typedef struct node {
  int parent;
  int left;
  int right;
}Node;

/* Prototype Declaration */
void setDepth(int, int);
void printChildren(int);
int setHeight(int);

/* Global Variables */
Node U[MAX];
int depth[MAX], height[MAX];

int main () {
  int i, j, n, id, data, r, h;

  scanf("%d", &n);

  for ( i = 0; i < n; i++ ) {
    U[i].parent = NIL;
    U[i].left = NIL;
    U[i].right = NIL;
  }

  for ( i = 0; i < n; i++ ) {
    scanf("%d", &id);
    for ( j = 0; j < 2; j++ ) {
      scanf("%d", &data);
      if ( j == 0 ) U[id].left = data;
      else U[id].right = data;

      U[data].parent = id;
      
    }
  }

  for ( i = 0; i < n; i++ ) {
    if( U[i].parent == NIL ) r = i;
  }

  setDepth(r, 0);
  h = setHeight(r);

  for ( i = 0; i < n; i++ ) printChildren(i);

  return 0;
  
}

void setDepth(int u, int p) {
  depth[u] = p;

  if ( U[u].right != NIL ) setDepth(U[u].right, p + 1);
  if ( U[u].left != NIL ) setDepth(U[u].left, p + 1);
}

int setHeight(int u) {
  int a, b;
  
  a = 0;
  b = 0;

  if ( U[u].left != NIL ) a = setHeight(U[u].left) + 1;
  if ( U[u].right != NIL ) b = setHeight(U[u].right) + 1;

  if ( a > b ) height[u] = a;
  else if ( a < b ) height[u] = b;
  else height[u] = a;

  return height[u];

}

void printChildren(int u) {
  int c = U[u].left;

  printf("node %d: ", u);
  printf("parent = %d, ", U[u].parent);
  printf("sibling = ");
  if ( U[u].parent != NIL && U[U[u].parent].left == u ) printf("%d, ", U[U[u].parent].right);
  else if ( U[u].parent != NIL && U[U[u].parent].right == u ) printf("%d, ", U[U[u].parent].left);
  else printf("-1, ");
  printf("degree = ");
  if( U[u].left == NIL && U[u].right == NIL ) printf("0, ");
  else if ( U[u].left != NIL && U[u].right != NIL ) printf("2, ");
  else printf("1, ");
  printf("depth = %d, ", depth[u]);
  printf("height = %d, ", height[u]);

  if ( U[u].parent == NIL ) printf("root");
  else if ( U[u].left == NIL && U[u].right == NIL ) printf("leaf");
  else printf("internal node");
  printf("\n");
}
