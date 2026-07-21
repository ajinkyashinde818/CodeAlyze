#include <stdio.h>

#define Max 26

int n, D[Max], H[Max], Deg[Max] = {0};

typedef struct {
  int parent;
  int left;
  int right;
} Node;

Node T[Max];

int max(int a, int b) {
  return a >= b ? a : b;
}

void get_depth(int u, int p) {
  D[u] = p;
  if (T[u].left != -1)  get_depth(T[u].left, p + 1);
  if (T[u].right != - 1) get_depth(T[u].right, p + 1);
}

int get_height(int u) {
  int h1 = 0, h2 = 0;
  if (T[u].right != -1) h1 = get_height(T[u].right) + 1;
  if (T[u].left != -1) h2 = get_height(T[u].left) + 1;

  return H[u] = max(h1, h2);
}

void print(void) {
  int i;
  for (i = 0; i < n; i++) {
    printf("node %d: ", i);
    printf("parent = %d, sibling = ", T[i].parent);

    if (i == T[T[i].parent].left && T[i].parent != -1) {
      printf("%d, degree = %d, depth = %d, height = %d, ", T[T[i].parent].right, Deg[i], D[i], H[i]);
    } else if (i == T[T[i].parent].right && T[i].parent != -1) {
      printf("%d, degree = %d, depth = %d, height = %d, ", T[T[i].parent].left, Deg[i], D[i], H[i]);
    } else {
      printf("-1, degree = %d, depth = %d, height = %d, ", Deg[i], D[i], H[i]);
    }

    if (T[i].parent == -1) {
      printf("root\n");
    } else if (Deg[i] == 0) {
      printf("leaf\n");
    } else {
      printf("internal node\n");
    }

  }
}

int main(int argc, char const *argv[]) {
  int i, c, l, r, root;
  for (i = 0; i < Max; i++) {
    T[i].parent = -1;
    T[i].left = -1;
    T[i].right = -1;
  }

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d %d %d", &c, &l, &r);
    T[c].left = l, T[c].right = r;
    if (T[c].left != -1)  {
      T[T[c].left].parent = c;
      Deg[c]++;
    }
    if (T[c].right != -1) {
      T[T[c].right].parent = c;
      Deg[c]++;
    }
  }
  for (i = 0; i < n; i++) {
    if (T[i].parent == -1)  root = i;
  }
  get_depth(root, 0);
  c = get_height(root);
  print();

  return 0;
}
