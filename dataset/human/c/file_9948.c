#include <stdio.h>
#include <stdlib.h>

typedef struct _n {
  int id;
  int dim;
  int *children;
  int parent;
  int depth;
} node;
node tree[100000];
void setDepth(int);
int main() {
  int i, j, k, n;
  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    tree[i].parent = -1;
    tree[i].depth = 0;
  }
  for(k = 0; k < n; k++) {
    scanf("%d", &i);
    tree[i].id = i;
    scanf("%d", &tree[i].dim);
    tree[i].children = (int *) malloc(sizeof(int) * tree[i].dim);
    for(j = 0; j < tree[i].dim; j++) {
      scanf("%d", &tree[i].children[j]);
      tree[tree[i].children[j]].parent = tree[i].id;
    }
  }
  for(i = 0; i < n; i++) {
    if(tree[i].parent == -1) k = i;
  }
  setDepth(k);
  for(i = 0; i < n; i++) {
    printf("node %d: parent = %d, depth = %d, ", tree[i].id, tree[i].parent, tree[i].depth);
    if(tree[i].parent == -1) {
      printf("root, [");
      for(j = 0; j < tree[i].dim; j++) {
	printf("%d", tree[i].children[j]);
	if(j != tree[i].dim -1) printf(", ");
      }
    }
    else if(tree[i].dim == 0) {
      printf("leaf, [");
    }
    else {
      printf("internal node, [");
      for(j = 0; j < tree[i].dim; j++) {
	printf("%d", tree[i].children[j]);
	if(j != tree[i].dim -1) printf(", ");
      }
    }
    printf("]\n");
  }
  return 0;
}

void setDepth(int r) {
  int i;
  for(i = 0; i < tree[r].dim; i++) {
    tree[tree[r].children[i]].depth += 1 + tree[r].depth;
    setDepth(tree[r].children[i]);
  }
}
