#include <stdio.h>

struct Node{
  int parent;
  int left;
  int right;
};

struct Node node[25];

void setup(struct Node node[], int n) {
  for (int i = 0; i < n; i++) {
    node[i].parent = -1;
    node[i].left = -1;
    node[i].right = -1;
  }
}

void input(struct Node node[], int n) {
  int id, cleft, cright;
  for (int i = 0; i < n; i++) {
    scanf("%d", &id);
    scanf("%d", &cleft);
    scanf("%d", &cright);
    node[id].left = cleft;
    node[id].right = cright;
    node[cleft].parent = id;
    node[cright].parent = id;
  }
}

void search_bro(struct Node node[], int id) {
  int oya;
  oya = node[id].parent;

  if (oya == -1) {
    printf("%d", oya);
    return;
  }
  else if (node[oya].left != id && node[oya].right == id) {
    if (node[oya].left != -1)
      printf("%d", node[oya].left);
    else
      printf("-1");
  }
  else {
    if (node[oya].right != -1)
      printf("%d", node[oya].right);
    else
      printf("-1");
  }
}

int search_deg(struct Node node[], int id) {
  int count = 0;
  if (node[id].left != -1)
    count++;
  if (node[id].right != -1)
    count++;
  return count;
}

int search_height(struct Node *node, int id) {
  int lheight = 0, rheight = 0;
  if (node[id].left == -1 && node[id].right == -1)
    return 0;
  else {
    if (node[id].left != -1)
      lheight = 1 + search_height(&node[0], node[id].left);
    if (node[id].right != -1)
      rheight = 1 + search_height(&node[0], node[id].right);
    if (lheight >= rheight)
      return lheight;
    else
      return rheight;
 }
}

void search_type(struct Node node[], int id) {
  if (node[id].parent == -1)
    printf("root");
  else if (node[id].left != -1 || node[id].right != -1)
    printf("internal node");
  else
    printf("leaf");
}

int search_dep(struct Node node[], int id) {
  int dep = 0;
  while (node[id].parent != -1) {
    dep++;
    id = node[id].parent;
  }
  return dep;
}

void output(struct Node node[], int n) {
  for (int i = 0; i < n; i++) {
    printf("node %d: parent = %d, ", i, node[i].parent);
    printf("sibling = ");
    search_bro(node, i);
    printf(", ");
    printf("degree = %d, ", search_deg(node, i));
    printf("depth = %d, ", search_dep(node, i));
    printf("height = %d, ", search_height(&node[0], i));
    search_type(node, i);
    printf("\n");
  }
}

int main(void) {
  int n;
  
  scanf("%d", &n);

  setup(node, n);
  input(node, n);

  output(node, n);
  
  return 0;
}
