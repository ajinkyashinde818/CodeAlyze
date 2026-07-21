#include <stdio.h>
#define MAX 25
#define NIL -1

typedef struct {
  int parent;
  int left;
  int right;
} Binary;

int depth;
Binary T[MAX];

int max(int, int);
int calcDepth(int);
int calcHeight(int);
int findSibling(int);
void print(int);


int main() {
  int n, i, p, l, r;
  
  scanf( "%d" , &n );
  for ( i=0; i<n; i++ ) T[i].parent = T[i].left = T[i].right = NIL;
  for ( i=0; i<n; i++ ) {
    scanf("%d%d%d", &p, &l, &r);
    T[l].parent = T[r].parent = p;
    T[p].left = l;
    T[p].right = r;
  }
  
  for ( i=0; i<n; i++ ) print(i);
  
  return 0;
}


int max(int a, int b) {
  if ( a > b ) return a;
  else return b;
}

int calcDepth(int u) {
  if ( T[u].parent == NIL ) return 0;
  else {
    depth++;
    calcDepth(T[u].parent);
  }
  return depth;
}

int calcHeight(int u) {
  int h1=0, h2=0;

  if ( T[u].left != NIL ) h1 = calcHeight(T[u].left) + 1;
  if ( T[u].right != NIL ) h2 = calcHeight(T[u].right) + 1;

  return max(h1, h2);
}

int findSibling(int u) {
  if ( T[u].parent == NIL ) return NIL;
  else if ( (T[T[u].parent].left != u)
	    && (T[T[u].parent].left != NIL) )
    return T[T[u].parent].left;
  else if ( (T[T[u].parent].right != u)
	    && (T[T[u].parent].right != NIL) )
    return T[T[u].parent].right;
  else return NIL;
}

void print(int u) {
  int degree=0;

  printf( "node %d: parent = %d, sibling = %d, "
	  , u , T[u].parent , findSibling(u) );
  
  if ( T[u].right != NIL ) degree++;
  if ( T[u].left != NIL ) degree++;
  printf( "degree = %d, " , degree );
  
  depth = 0;
  printf( "depth = %d, height = %d, " , calcDepth(u) , calcHeight(u) );
  
  if ( T[u].parent == NIL ) printf( "root\n" );
  else if ( (T[u].left == NIL)
	    && (T[u].right == NIL) ) printf( "leaf\n" );
  else printf( "internal node\n" );
}
