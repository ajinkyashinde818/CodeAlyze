#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
  int right, left, parent;
  int depth, height;
} node;

node tree[25];

void setDepth(int id, int d) {
  tree[id].depth = d;
  if(tree[id].right != -1)
    setDepth(tree[id].right, d + 1);
  if(tree[id].left != -1)
    setDepth(tree[id].left, d + 1);

  return;
}

int setHeight(int id) {
  if(tree[id].right == -1 && tree[id].left == -1) {
    tree[id].height = 0;
    return 0;
  }

  int rightHeight, leftHeight, height;
  rightHeight = leftHeight = height = 0;

  if(tree[id].right != -1)
    rightHeight = setHeight(tree[id].right);
  if(tree[id].left != -1)
    leftHeight = setHeight(tree[id].left);

  height =  rightHeight > leftHeight ? rightHeight : leftHeight;
  tree[id].height = height + 1;
  return tree[id].height;
}

int main() {
  int i, n, id, left, right, root, sibling, degree;
  char type[20] = "";

  scanf("%d", &n);
  for(i = 0;i < n;i++) {
    tree[i].depth = -1;
    tree[i].height = -1;
    tree[i].parent = -1;
    tree[i].right = -1;
    tree[i].left = -1;
  }

  for(i = 0;i < n;i++) {
    scanf("%d %d %d", &id, &left, &right);
    tree[id].left = left;
    tree[id].right = right;
    if(left != -1)
      tree[left].parent = id;
    if(right != -1)
      tree[right].parent = id;
  }

  for(i = 0;i < n;i++)
    if(tree[i].parent == -1)
      root = i;

  setDepth(root, 0);
  setHeight(root);

  for(i = 0;i < n;i++) {
    sibling = -1;
    if(tree[i].parent != -1) {
      if(tree[tree[i].parent].right == i)
        sibling = tree[tree[i].parent].left;
      if(tree[tree[i].parent].left == i)
        sibling = tree[tree[i].parent].right;
    }

    degree = 0;
    if(tree[i].right != -1)
      degree++;
    if(tree[i].left != -1)
      degree++;

    if(tree[i].parent == -1)
      strcpy(type, "root");
    else if(tree[i].right != -1 || tree[i].left != -1)
      strcpy(type, "internal node");
    else if(tree[i].right == -1 && tree[i].left == -1)
      strcpy(type, "leaf");

    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n", i, tree[i].parent, sibling, degree, tree[i].depth, tree[i].height, type);
  }

  return 0;
}
