#include <stdio.h>
#define MAX 10001
#define NIL -1

struct Node{
  int p;
  int l;
  int r;
};

struct Node T[MAX];
int n;
int D[MAX];
int H[MAX];

int max(int h1, int h2){

  if( h1 < h2 )
    return h2;

  return h1;

}

int Height(int u){

  int h1 = 0;
  int h2 = 0;

  if( T[u].r != NIL ){
    h1 = Height(T[u].r ) + 1;
  }

  if( T[u].l != NIL ){
    h2 = Height(T[u].l) + 1;
  }

  return H[u] = max(h1,h2);

}

void Depth(int i, int d){
  if( i == NIL ) return;
  D[i] = d;
  Depth(T[i].l,d+1);
  Depth(T[i].r,d+1);

}

int Sibling(int i){

  if( T[i].p == NIL ){
    return NIL;
  }

  if( T[T[i].p].l != i && T[T[i].p].l != NIL ){
    return T[T[i].p].l;
  }

  if( T[T[i].p].r != i && T[T[i].p].r != NIL ){
    return T[T[i].p].r;
  }

  return NIL;

}

void print(int i){

  int deg = 0;

  printf("node %d: ",i);
  printf("parent = %d, ",T[i].p);
  printf("sibling = %d, ",Sibling(i));

  if( T[i].l != NIL ){
    deg++;
  }

  if( T[i].r != NIL ){
    deg++;
  }

  printf("degree = %d, ",deg);
  printf("depth = %d, ",D[i]);
  printf("height = %d, ",H[i]);

  if( T[i].p == NIL ){
    printf("root\n");
  }else if( T[i].l == NIL && T[i].r == NIL ){
    printf("leaf\n");
  }else{
    printf("internal node\n");
  }

}

int main(int argc, char const *argv[]) {

  int v,l,r;
  int root = 0;
  int i,j;

  scanf("%d",&n);

  for( i = 0 ; i < n ; i++ ){
    T[i].p = T[i].l = T[i].r = NIL;
  }

  for( i = 0 ; i < n ; i++ ){
    scanf("%d %d %d",&v,&l,&r);
    T[v].l = l;
    T[v].r = r;

    if( l != NIL ){
      T[l].p = v;
    }
    if( r != NIL ){
      T[r].p = v;
    }

  }

  for( i = 0 ; i < n ; i++ ){

    if( T[i].p == NIL ){
      root = i;
    }

  }


  Depth(root,0);
  Height(root);

  for( i = 0 ; i < n ; i++ ){
    print(i);
  }

  return 0;
}
