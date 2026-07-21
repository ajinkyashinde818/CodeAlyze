#include <stdio.h>
#define MAX 10000
 
struct Node{
  int parent, left, right;
};
 
struct Node Tree[MAX];
int n, D[MAX],H[MAX];
 
void depth( int i, int k ){
  if( i == -1 )return;
  D[i] = k;
  depth( Tree[i].left, k + 1 );
  depth( Tree[i].right, k + 1 );
}
 
int height( int i ){
  int h1 = 0, h2 = 0;
  if( Tree[i].left != -1 ){
    h1 = height( Tree[i].left ) + 1;
  }
  if( Tree[i].right != -1 ){
    h2 = height( Tree[i].right ) + 1;
  }
 
  if( h1 < h2 ) return H[i] = h2;
  else return H[i] = h1;
}
 
int sibling( int i ){
  if( Tree[i].parent == -1 )return -1;
  if( Tree[Tree[i].parent].left != -1 && Tree[Tree[i].parent].left != i ){
    return Tree[Tree[i].parent].left;
  }
  if( Tree[Tree[i].parent].right != -1 && Tree[Tree[i].parent].right != i ){
    return Tree[Tree[i].parent].right;
  }
  return -1;
}
 

int main(){
  int v,l,r,root = 0,i,deg;
  scanf("%d",&n);
 
  for( i = 0 ; i < n ; i++ ){
    Tree[i].parent = -1;
  }
  for( i = 0 ; i < n ; i++ ){
    scanf("%d %d %d", &v, &l, &r);
    Tree[v].left = l;
    Tree[v].right = r;
    if( l != -1 )Tree[l].parent = v;
    if( r != -1 )Tree[r].parent = v;
  }
 
  for( i = 0 ; i < n ; i++ ){
    if( Tree[i].parent == -1 )root = i;
  }

  depth( root, 0 );
  height( root );

  for( i = 0 ; i < n ; i++ ){
    printf("node %d: parent = %d, sibling = %d, ", i,Tree[i].parent,sibling(i));
    deg = 0;
    if( Tree[i].left != -1 )deg++;
    if( Tree[i].right != -1 )deg++;
    printf("degree = %d, depth = %d, height = %d, ", deg,D[i],H[i]);
    if( Tree[i].parent == -1 ){
      printf("root\n");
    }
    else if( Tree[i].left == -1 && Tree[i].right == -1 ){
      printf("leaf\n");
    }
    else{
      printf("internal node\n");
    }
  } 
  return 0;
}
