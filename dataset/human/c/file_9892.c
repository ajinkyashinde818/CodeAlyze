#include <stdio.h>

#define Max 100001

typedef struct {
  int par, chi, bro;
} Node;

Node T[Max];
int D[Max], n;

void get_depth(int u, int p) {
  D[u] = p;
  if (T[u].bro != -1) get_depth(T[u].bro, p);
  if (T[u].chi != -1) get_depth(T[u].chi, p + 1);
}

void print(int u) {
  int i, c;
  for (i = 0; i < n; i++) {
    int count = 0;
    printf("node %d: ", i);
    printf("parent = %d, ", T[i].par);
    printf("depth = %d, ", D[i]);

    if (T[i].par == -1) {
      printf("root, ");
    } else if (T[i].chi == -1) {
      printf("leaf, ");
    } else {
      printf("internal node, ");
    }

    printf("[");
    c = T[i].chi;

    while (c != - 1) {
      if (count > 0) printf(", ");
      printf("%d", c);
      c = T[c].bro;
      count++;
    }
    printf("]\n");
  }
}

int main(int argc, char const *argv[]) {
  int i, j, m, child, parent, brother, current, root;
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    T[i].par = -1;
    T[i].chi = -1;
    T[i].bro = -1;
  }

  for (i = 0; i < n; i++) {
    scanf("%d %d", &parent, &m);
    for (j = 0; j < m; j++) {
      scanf("%d", &current);
      if (j == 0) T[parent].chi = current;
      else T[child].bro = current;
      child = current;
      T[current].par = parent;
    }
  }

  for (i = 0; i < n; i++) {
    if (T[i].par == -1)  root = i;
  }

  get_depth(root, 0);

  print(i);

  return 0;
}
