#include <stdio.h>
#include <string.h>
#define MAX 30
#define NIL -1

struct Node_struct {
  int p, l, r;
};

typedef struct Node_struct Node;
Node T[MAX];
int D[MAX];
int H[MAX];

void print(int u) {
  int i, d = 0;
  printf("node %d: parent = %d, sibling = ", u, T[u].p);
  if (T[u].p == NIL) printf("-1, ");
  else if ((T[T[u].p].l != NIL) && (T[T[u].p].l != u)) printf("%d, ",T[T[u].p].l);
  else if ((T[T[u].p].r != NIL) && (T[T[u].p].r != u)) printf("%d, ",T[T[u].p].r);
  else printf("-1, ");
  if (T[u].l != NIL) d++;
  if (T[u].r != NIL) d++;
  printf("degree = %d, depth = %d, height = %d, ", d, D[u], H[u]);
  if (T[u].p == NIL) printf("root\n");
  else if ((T[u].l == NIL) && (T[u].r == NIL)) printf("leaf\n");
  else printf("internal node\n");
}

void calcDepth(int u, int p) {
  D[u] = p;
  if (T[u].l != NIL) calcDepth(T[u].l, p + 1);
  if (T[u].r != NIL) calcDepth(T[u].r, p + 1);
}

int calcHeight(int u) {
  int h1 = 0, h2 = 0;
  if (T[u].l != NIL) h1 = calcHeight(T[u].l) + 1;
  if (T[u].r != NIL) h2 = calcHeight(T[u].r) + 1;
  if (h1 > h2) H[u] = h1;
  else H[u] = h2;
  return H[u];
}

int main() {
  int i, n, root = 0, v, l, r;
  memset(T, NIL, sizeof(T));
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d%d%d", &v, &l, &r);
    if (l != NIL) {
      T[v].l = l;
      T[l].p = v;
    }
    if (r != NIL) {
      T[v].r = r;
      T[r].p = v;
    }
  }
  for (i = 0; i < n; i++) {
    if (T[i].p == NIL) {
      root = i;
      break;
    }
  }
  calcDepth(root, 0);
  calcHeight(root);
  for (i = 0; i < n; i++) print(i);
  return 0;
}
