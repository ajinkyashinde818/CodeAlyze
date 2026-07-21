#include <stdio.h>
#include <string.h>

#define N 32

typedef struct {
  int parent;
  int left;
  int right;
  int depth;
  int height;
} node_t;

void dfs(node_t *array, int id, int d) {
  int left, right;

  if (id == -1)
    return;

  left = array[id].left;
  right = array[id].right;
  array[id].depth = d;

  if (left != -1)
    dfs(array, left, d+1);
  if (right != -1)
    dfs(array, right, d+1);

  // calculate height
  if (left == -1 && right == -1)
    array[id].height = 0;
  else if (left != -1 && right == -1)
    array[id].height = array[left].height + 1;
  else if (left == -1 && right != -1)
    array[id].height = array[right].height + 1;
  else {
    if (array[right].height < array[left].height)
      array[id].height = array[left].height + 1;
    else
      array[id].height = array[right].height + 1;
  }
}

int main(void) {
  int i, n, pid, left, right, degree, parent, sibling;
  char *type;
  node_t array[N];
  memset(array, -1, sizeof(array));

  // input
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &pid);
    scanf("%d %d", &left, &right);
    if (left != -1)
      array[left].parent = pid;
    if (right != -1)
      array[right].parent = pid;
    array[pid].left = left;
    array[pid].right = right;
  }

  // calculate depth
  for (i = 0; i < n; i++) {
    if (array[i].parent == -1) {
      dfs(array, i, 0);
      break;
    }
  }

  // output
  for (i = 0; i < n; i++) {
    parent = array[i].parent;

    // determination a sibling node
    if (i == array[parent].right)
      sibling = array[parent].left;
    else if (i == array[parent].left)
      sibling = array[parent].right;
    else
      sibling = -1;
    
    // calculate degree
    if (array[i].left == -1 && array[i].right == -1)
      degree = 0;
    else if(array[i].left != -1 && array[i].right != -1)
      degree = 2;
    else
      degree = 1;

    // determination a node type
    if (parent == -1)
      type = "root";
    else if (degree == 0)
      type = "leaf";
    else
      type = "internal node";
    
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n", i, parent, sibling, degree, array[i].depth, array[i].height, type);
  }

  return 0;
}
