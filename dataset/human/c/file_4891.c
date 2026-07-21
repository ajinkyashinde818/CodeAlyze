#include <stdio.h>
#define MAX 25
struct Node{
  int parent;
  int left;
  int right;
};

struct Node T[MAX];
int D[MAX], H[MAX];

void calDepth(int i, int d) {
  if (i == -1) return;
  D[i] = d;
  calDepth(T[i].left, d+1);
  calDepth(T[i].right, d+1);
}

int calHeight(int i) {
  int h1 = 0, h2 = 0;
  if (T[i].left != -1) {
    h1 = calHeight(T[i].left) + 1;
  }
  if (T[i].right != -1) {
    h2 = calHeight(T[i].right) + 1;
  }

  if (h1 >= h2) {
    return H[i] = h1;
  } else {
    return H[i] = h2;
  }
}

int pickSibling(int i) {
  if (T[i].parent == -1) return -1;
  if (T[T[i].parent].left != i && T[T[i].parent].left != -1) {
    return T[T[i].parent].left;
  }
  if (T[T[i].parent].right != i && T[T[i].parent].right != -1) {
    return T[T[i].parent].right;
  }
  return -1;
}

void print(int i) {
  printf("node %d: ", i);
  printf("parent = %d, ", T[i].parent);
  printf("sibling = %d, ", pickSibling(i));

  int c;
  c = 0;
  if (T[i].left != -1) c++;
  if (T[i].right != -1) c++;
  printf("degree = %d, ", c);

  printf("depth = %d, ", D[i]);
  printf("height = %d, ", H[i]);

  if (T[i].parent == -1) {
    printf("root");
    printf("\n");
  } else if (T[i].left == -1 && T[i].right == -1) {
    printf("leaf");
    printf("\n");
  } else {
    printf("internal node");
    printf("\n");
  }
}

int main(void) {
  int n;
  scanf("%d", &n);
  int i;
  for (i = 0; i < MAX; i++) {
    T[i].parent = -1;
    T[i].left = -1;
    T[i].right = -1;
  }

  for (i = 0; i < n; i++) {
    int id;
    int l, r;
    scanf("%d %d %d", &id, &l, &r);
    T[id].left = l;
    T[id].right = r;
    if (l != -1) T[l].parent = id;
    if (r != -1) T[r].parent = id;
  }

  int r;
  for (i = 0; i < n; i++) {
    if (T[i].parent == -1) r = i;
  }

  calDepth(r, 0);
  calHeight(r);

  for (i = 0; i < n; i++) {
    print(i);
  }

  return 0;
}
