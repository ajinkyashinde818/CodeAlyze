#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct {
  int parent;
  int left;
  int right;
} Node;

Node node[26];

int getSibling(int id) {
  int p = node[id].parent;
  if (p == -1) return -1;

  return node[p].left == id ? node[p].right : node[p].left;
}

int getDegree(int id) {
  int cnt = 0;
  
  if (node[id].right != -1) cnt++;
  if (node[id].left != -1) cnt++;

  return cnt;
}

int getHeight(int id, int h) {
  int left;
  int right;
  if (id == -1) {
    return h - 1;
  }
  
  left = node[id].left;
  right = node[id].right;
  h += 1;
  return MAX(getHeight(left, h), getHeight(right, h));
}

int getDepth(int id, int d) {
  if (node[id].parent != -1) {
    return getDepth(node[id].parent, ++d);
  }
  else {
    return d;
  }
}

char *getType(int id) {
  if (node[id].parent == -1) {
    return "root";
  }
  else if (node[id].left == -1 && node[id].right == -1) {
    return "leaf";
  }
  else {
    return "internal node";
  }
}

void printNode(int id) {
  printf("node %d: ", id);
  printf("parent = %d, ", node[id].parent);
  printf("sibling = %d, ", getSibling(id));
  printf("degree = %d, ", getDegree(id));
  printf("depth = %d, ", getDepth(id, 0));
  printf("height = %d", getHeight(id, 0));
  printf(", %s", getType(id));
  printf("\n");
}

int main() {
  int n, id, left, right;
  int i;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    node[i].parent = -1;
  }

  for (i = 0; i < n; i++) {
    scanf("%d %d %d", &id, &left, &right);
    node[id].left = left;
    node[id].right = right;
    if (left != -1) {
      node[left].parent = id;
    }
    if (right != -1) {
      node[right].parent = id;
    }
    
  }

  for (i = 0; i < n; i++) {
    printNode(i);
  }

  return 0;
}
