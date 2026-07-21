#include<stdio.h>

const static int MAX = 10000;
const static int NIL = -1;

typedef struct {
    int parent, left, right;
} Node;

Node T[MAX];
int n, D[MAX], H[MAX];

void setDepth(int u, int d) {
  if (u == NIL) return;
  D[u] = d;

  setDepth(T[u].left, d + 1);
  setDepth(T[u].right, d + 1);
}

int setHeight(int u) {
  int h1 = 0;
  int h2 = 0;

  if (T[u].left != NIL) {
    h1 = setHeight(T[u].left) + 1;
  }
  if (T[u].right != NIL) {
    h2 = setHeight(T[u].right) + 1;
  }

  H[u] = h1 > h2 ? h1 : h2;

  return H[u];
}

int getSibling(int u) {
  for (int i = 0; i < n; i++) {
    if (T[i].right == u) return T[i].left;
    else if (T[i].left == u) return T[i].right;
  }
  return NIL;
}

int main() {
  int v, l, r, root = 0;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) T[i].parent = NIL;
  
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &v, &l, &r);
    T[v].left = l;
    T[v].right = r;
    if (l != NIL)
      T[l].parent = v;
    if (r != NIL)
      T[r].parent = v;
  }

  for (int i = 0; i < n; i++) {
    if (T[i].parent == NIL) {
      root = i;
      break;
    }
  }

  setHeight(root);
  setDepth(root, 0);

  for (int i = 0; i < n; i++) {
    printf("node %d: parent = %d, sibling = %d, ", i, T[i].parent, getSibling(i));
    int cnt = 0;
    if (T[i].left != NIL) cnt += 1;
    if (T[i].right != NIL) cnt += 1;
    printf("degree = %d, depth = %d, height = %d, ", cnt, D[i], H[i]);
    if (root == i) printf("root");
    else if (cnt == 0) printf("leaf");
    else printf("internal node");
    printf("\n");
  }

  return 0;
}
