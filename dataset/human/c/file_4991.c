#include <stdio.h>
#define N 25

typedef struct{
  int id;
  int parent;
  int left;
  int right;
  int sibling;
} Node;

int heightCheck(Node node[], int i){
  int height = 0;
  int left, right;

  if( node[i].left == -1 && node[i].right == -1 ) return height;
  else if( i == -1 ) return height;

  left = heightCheck(node, node[i].left);
  right = heightCheck(node, node[i].right);
  if( left > right ) return left+1;
  else return right+1;

}


main(){
  int n, i, j;
  int id, left, right, depth, parent;
  Node node[N];

  scanf("%d", &n);

  for( i = 0; i < n; i++){
    node[i].parent = -1;
    node[i].sibling = -1;
  }

  for( i = 0; i < n; i++){
    scanf("%d%d%d", &id, &left, &right);

    node[id].id = id;
    node[id].left = left;
    node[id].right = right;

    if( left != -1 || right != -1){
      node[left].parent = id;
      node[right].parent = id;
      node[left].sibling = right;
      node[right].sibling = left;
    }

  }

  for( i = 0; i < n; i++){
    printf("node %d: parent = %d, sibling = %d, ", node[i].id, node[i].parent, node[i].sibling);

    if( node[i].left == -1 && node[i].right == -1 ) printf("degree = 0, ");
    else if( node[i].left == -1 || node[i].right == -1 ) printf("degree = 1, ");
    else printf("degree = 2, ");

    depth = 0;
    parent = node[i].parent;
    while(1){
      if( parent == -1 ) break;
      else {
        parent = node[parent].parent;
        depth++;
      }
    }

    printf("depth = %d, ", depth);

    printf("height = %d, ", heightCheck(node, i));

    if( node[i].parent == -1 ){
      printf("root");
    }
    else if( node[i].left == -1 && node[i].right == -1){
      printf("leaf");
    }
    else printf("internal node");

    printf("\n");
  }

  return 0;

}
