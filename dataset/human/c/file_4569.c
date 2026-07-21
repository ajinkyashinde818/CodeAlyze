#include<stdio.h>
#define N 200000
#define NIL -1
typedef struct Node {
  int parent;
  int left;
  int right;
} node;
int n, depth[N], height[N];
node tree[N];
void culDepth(int, int);
void culheight(int);
int getSibiling(int);
void print(int);
int main() {
  int node, i, j, k, left, right, rooti;
  for (i = 0; i < N; i++) {
    tree[i].parent = NIL;
    tree[i].left = NIL;
    tree[i].right = NIL;
  }
  scanf("%d",&n);
  for (i = 0; i < n; i++) {
    scanf("%d %d %d", &node, &left, &right);
    tree[node].left = left;
    tree[node].right = right;
    if (left != NIL) {
      tree[left].parent = node;
    }
    if (right != NIL) {
      tree[right].parent = node;
    }
  }
  for (i = 0; i < n; i++) {
    if (tree[i].parent == NIL) {
      rooti = i;
    }
  }
  culDepth(rooti, 0);
  culHeight(rooti);
  for (i = 0; i < n; i++) {
    print(i);
  }
  return 0;
}
void culDepth(int i, int d) {
  depth[i] = d;
  if (tree[i].left != NIL) {
    culDepth(tree[i].left, d + 1);
  }
  if (tree[i].right != NIL) {
    culDepth(tree[i].right, d + 1);
  }
  return;
}
int culHeight(int i) {
  int h1, h2;
  h1 = 0;
  h2 = 0;
  if (tree[i].left != NIL) {
    h1 = culHeight(tree[i].left) + 1;
  }
  if (tree[i].right != NIL) {
    h2 = culHeight(tree[i].right) + 1;
  }
  if (h1 < h2) {
    height[i] = h2;
  } else {
    height[i] = h1;
  }
  return height[i];
}
int getSibiling(int i) {
  int j, k;
  if (tree[i].parent == NIL) {
    return NIL;
  }
  if (tree[tree[i].parent].left != i && tree[tree[i].parent].left != NIL) {
    return  tree[tree[i].parent].left;
  }
  if (tree[tree[i].parent].right != i && tree[tree[i].parent].left != NIL) {
    return tree[tree[i].parent].right;
  }
  return NIL;
}
void print(int i) {
  int deg = 0;
  printf("node %d: parent = %d, sibling = %d, ", i, tree[i].parent, getSibiling(i));
  printf("degree = ");
  if (tree[i].left != NIL) {
    deg++;
  }
  if (tree[i].right != NIL) {
    deg++;
  }
  printf("%d, ", deg);
  printf("depth = %d, height = %d, ", depth[i], height[i]);
  if (tree[i].parent == NIL) {
    printf("root\n");
  } else if (tree[i].left == NIL && tree[i].right == NIL) {
    printf("leaf\n");
  } else {
    printf("internal node\n");
  }
}
