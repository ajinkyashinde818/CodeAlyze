#include<stdio.h>

#define M 10000
#define N -1

struct Node{
  int parent;
  int left;
  int right;
};

struct Node T[M];
int n,D[M],H[M];

void setDepth(int u,int d){
  if( u == N )
    return;
  D[u]=d;
  setDepth( T[u].left,d+1 );
  setDepth( T[u].right,d+1 );
}

int setHeight(int u){
  int h1=0;
  int h2=0;

  if( T[u].left != N )
    h1=setHeight(T[u].left)+1;

  if( T[u].right != N )
    h2=setHeight(T[u].right)+1;

  return H[u] = (h1 > h2 ? h1 : h2);
}

int getSibling(int u){
  if( T[u].parent == N )
    return N;

  if( T[T[u].parent].left !=
      u && T[T[u].parent].left != N )
    return T[T[u].parent].left;

  if( T[T[u].parent].right !=
      u && T[T[u].parent].right != N )
    return T[T[u].parent].right;

  return N;
}

void p(int u){
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].parent);
  printf("sibling = %d, ",getSibling(u));

  int deg=0;

  if( T[u].left != N )
    deg++;

  if( T[u].right != N )
    deg++;

  printf("degree = %d, ",deg);
  printf("depth = %d, ",D[u]);
  printf("height = %d, ",H[u]);

  if( T[u].parent == N ){
    printf("root\n");
  }
  else if( T[u].left == N && T[u].right == N ){
    printf("leaf\n");
  }
  else{
    printf("internal node\n");
  }
}

int main(){
  int v,l,r,root=0;

  scanf("%d",&n);

  for( int i=0; i<n; i++ )
    T[i].parent = N;

  for( int i=0; i<n; i++ ){
    scanf("%d %d %d",&v,&l,&r);

    T[v].left=l;
    T[v].right=r;

    if( l != N )
      T[l].parent = v;

    if( r != N)
      T[r].parent = v;
  }

  for( int i=0; i<n; i++ )
    if( T[i].parent == N )
      root=i;

  setDepth(root,0);
  setHeight(root);

  for( int i=0; i<n; i++ )
    p(i);

  return 0;
}
