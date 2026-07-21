#include<stdio.h>
#define N 100000

typedef struct {
  int parent;
  int left;
  int right;
} Node;

Node Tree[N];

int getDepth(int x) {
  int depth = 1;
  if(Tree[x].parent == -1) return 0;
  depth += getDepth(Tree[x].parent);
  return depth;
}

int main() {
  int i, j, n, m, k, p;
  int number, depth, child; 

  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    Tree[i].parent = -1;
    Tree[i].left = -1;
    Tree[i].right = -1;
  }
  for(i = 0; i < n; i++) {
    scanf("%d", &number);
    scanf("%d", &m);
    for(j = 0; j < m; j++) {
      scanf("%d", &child);
      Tree[child].parent = number;
      if(j == 0) {
	Tree[number].left = child;
      }
      else {
	Tree[k].right = child;
      }
      k = child;
    }
  }

  for(i = 0; i < n; i++) {
    depth = getDepth(i);
    printf("node %d: parent = %d, depth = %d, ", i, Tree[i].parent, depth);
    if( Tree[i].parent == -1) {
      printf("root, [");
      if(Tree[i].left != -1) {
	printf("%d",Tree[i].left );
	p = Tree[i].left;
	while(Tree[p].right != -1) {
	  printf(", %d", Tree[p].right);
	  p = Tree[p].right;
	    }
      }
      printf("]\n");
    }
  
    else if(Tree[i].left != -1){
      printf("internal node, [");
      if(Tree[i].left != -1) {
	printf("%d",Tree[i].left );
	p = Tree[i].left;
	while(Tree[p].right != -1) {
	  printf(", %d", Tree[p].right);
	  p = Tree[p].right;
	    }
      }
      printf("]\n");
    }
    else printf("leaf, []\n");
  }
  
  return 0;
}
