#include <stdio.h>

#define MAX 100000

int getDepth(int);
int getSibling(int);
int getHeight(int);

struct nibunki {
  int parent;
  int left;
  int right;
};

struct nibunki array[MAX];
int height[MAX];

int main(){

  int n, i, id, degree, left, right, root;

  scanf("%d", &n);

  for( i=0; i<n; i++){
    array[i].parent = array[i].left = array[i].right = -1;
  }

  for( i=0; i<n; i++){
    scanf("%d %d %d", &id, &left, &right);
    array[id].left = left;
    array[id].right = right;

    if( left != -1 ) array[left].parent = id;
    if( right != -1 ) array[right].parent = id;
  }

  for( i=0; i<n; i++){
    if( array[i].parent == -1 ) root = i;
  }

  getHeight(root);

  for( i=0; i<n; i++){
    printf("node %d: parent = %d, ", i, array[i].parent);

    printf("sibling = %d, ", getSibling(i));

    degree = 0;
    if( array[i].left != -1 ) degree++;
    if( array[i].right != -1 ) degree++;

    printf("degree = %d, ", degree);

    printf("depth = %d, ", getDepth(i));

    printf("height = %d, ", height[i]);

    if( array[i].parent == -1 ) printf("root");
    else if( array[i].left == -1 && array[i].right == -1 ) printf("leaf");
    else printf("internal node");

    printf("\n");
  }

  return 0;
}

int getDepth(int u){
  int d=0;

  while( array[u].parent != -1 ){
    u = array[u].parent;
    d++;
  }

  return d;
}

int getSibling(int u){
  int parent;

  parent = array[u].parent;

  if( parent == -1 ) return -1;

  if( array[parent].left != u && array[parent].left != -1 ) return array[parent].left;

  if( array[parent].right != u && array[parent].right != -1 ) return array[parent].right;

  return -1;
}

int getHeight(int u){
  int h1 = 0, h2 = 0;

  if( array[u].left != -1 ) h1 = getHeight(array[u].left) + 1;

  if( array[u].right != -1 ) h2 = getHeight(array[u].right) + 1;

  return height[u] = ( h1 > h2 ? h1 : h2 );
}
