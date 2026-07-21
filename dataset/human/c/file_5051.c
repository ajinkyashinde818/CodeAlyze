#include<stdio.h>
#define MAX 10000
#define NIL -1

struct Node{
  int parent, left, right;
};

struct Node T[MAX];
int n, D[MAX],H[MAX];

void depth( int s, int d ){
  if( s == NIL )return;
  D[s] = d;
  depth( T[s].left, d + 1 );
  depth( T[s].right, d + 1 );
}

int height( int s ){
  int h1 = 0, h2 = 0;
  if( T[s].left != NIL ){
    h1 = height( T[s].left ) + 1;
  }
  if( T[s].right != NIL ){
    h2 = height( T[s].right ) + 1;
  }

  if( h1 < h2 )return H[s] = h2;
  else return H[s] = h1;
}

int sibling( int s ){
  if( T[s].parent == NIL )return NIL;
  if( T[T[s].parent].left != NIL && T[T[s].parent].left != s ){
    return T[T[s].parent].left;
  }
  if( T[T[s].parent].right != NIL && T[T[s].parent].right != s ){
    return T[T[s].parent].right;
  }
  return NIL;
}

void print( int s ){
  printf("node %d: ", s);
  printf("parent = %d, ",T[s].parent);
  printf("sibling = %d, ",sibling(s));
  int deg = 0;
  if( T[s].left != NIL )deg++;
  if( T[s].right != NIL )deg++;
  printf("degree = %d, ", deg);
  printf("depth = %d, ", D[s]);
  printf("height = %d, ", H[s]);
  if( T[s].parent == NIL ){
    printf("root\n");
  }
  else if( T[s].left == NIL && T[s].right == NIL ){
    printf("leaf\n");
  }
  else{
    printf("internal node\n");
  }
}

int main( void ){
  int v,l,r,root = 0,i;
  scanf("%d",&n);

  for( i = 0 ; i < n ; i++ ){
    T[i].parent = NIL;
  }
  for( i = 0 ; i < n ; i++ ){
    scanf("%d %d %d", &v, &l, &r);
    T[v].left = l;
    T[v].right = r;
    if( l != NIL )T[l].parent = v;
    if( r != NIL )T[r].parent = v;
  }

  for( i = 0 ; i < n ; i++ ){
    if( T[i].parent == NIL )root = i;
  }
  depth( root, 0 );
  height( root );
  for( i = 0 ; i < n ; i++ )print(i);

  return 0;
}
