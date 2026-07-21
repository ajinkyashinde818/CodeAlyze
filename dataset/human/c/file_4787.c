#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int parent;
  int left;
  int right;
} node;


void initNode( node* a, int length) {
  int i;

  for( i=0; i<length; i++) {
    a[i].parent = -1;
  }

}


void scanNode( node* a, int length) {
  int i, id;

  for( i=0; i<length; i++) {
    scanf("%d", &id);

    scanf("%d%d", &a[id].left, &a[id].right);
    if( a[id].left != -1) {
      a[ a[id].left ].parent = id; //左の子の親はid
    }
    if( a[id].right != -1) {
      a[ a[id].right ].parent = id; //右の子の親はid
    }
  }

}

int searchSibling( node* a, int id) {

  if( a[id].parent == -1 ) {
    return -1;
  }
  
  if (a[ a[id].parent ].right == id ) {
    return a[ a[id].parent ].left;
  }else {
    return  a[ a[id].parent ].right;
  }
  return 0;

}

int searchDegree( node* a, int id) {
  int degree = 0;

  if( a[id].left != -1 ) {
    degree += 1;
  }
  if( a[id].right != -1 ) {
    degree += 1;
  }

  return degree;

}


int searchDepth( node* a, int id) {

  if( a[id].parent == -1 ) {
    return 0;
  }else {
    return searchDepth( a, a[id].parent)+1;
  }

}


int searchHeight( node* a, int id) {

  int left, right;

  if( a[id].left == -1 ) {
    left = -1;
  }else {
    left = searchHeight( a, a[id].left);
  }

  if( a[id].right == -1 ) {
    right = -1;
  }else {
    right = searchHeight( a, a[id].right);
  }

  if( left > right ) {
    return left+1;
  }else {
    return right+1;
  }

}


void printNode( node* a, int length) {
  int i;

  for( i=0; i<length; i++) {
    printf("node %d: parent = %d, ", i, a[i].parent);
    printf("sibling = %d, ", searchSibling( a, i));
    printf("degree = %d, ", searchDegree( a, i));
    printf("depth = %d, ", searchDepth( a, i));
    printf("height = %d, ", searchHeight( a, i));




    if( a[i].parent == -1 ) {
      printf("root\n");
    }else if( searchDegree( a, i) >= 1 ) {
      printf("internal node\n");
    }else {
      printf("leaf\n");
    }

  }
    
}


int main() {

  int n, id;
  node* a;

  int i;

  scanf("%d", &n);

  a = (node* )malloc( sizeof( node ) * n);

  initNode( a, n);

  scanNode( a, n);

  printNode( a, n);

  return 0;

}
