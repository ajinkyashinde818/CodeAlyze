#include <stdio.h>

#define M 25

struct A{
  int parent;
  int left;
  int right;
};

struct A B[M];
int C[M], D[M];

void Depth(int i, int d);
int Height(int i); 
int pick(int i);
void pr(int i);

int main(void) {
  int n,i,d,le,ri;
  scanf("%d", &n);
  
  for (i = 0; i < M; i++) {
    
    B[i].parent = -1;
    B[i].left = -1;
    B[i].right = -1;
  }

  for (i = 0; i < n; i++) {

    scanf("%d %d %d", &d, &le, &ri);
    B[d].left = le;
    B[d].right = ri;
    if (le != -1) B[le].parent = d;
    if (ri != -1) B[ri].parent = d;
  }

  for (i = 0; i < n; i++) {
    if (B[i].parent == -1) ri = i;
  }

  Depth(ri, 0);
  Height(ri);

  for (i = 0; i < n; i++) {
    pr(i);
  }

  return 0;
}
void Depth(int a, int b) {
  if (a == -1) return;
  D[a] = b;
  Depth(B[a].left, b+1);
  Depth(B[a].right, b+1);
}
int Height(int a) {
  int b1 = 0, b2 = 0;
  if (B[a].left != -1) {
    b1 = Height(B[a].left) + 1;
  }
  if (B[a].right != -1) {
    b2 = Height(B[a].right) + 1;
  }

  if (b1 >= b2) {
    return C[a] = b1;
  } else {
    return C[a] = b2;
  }
}
int pick(int a) {
  if (B[a].parent == -1) return -1;
  if (B[B[a].parent].left != a && B[B[a].parent].left != -1) {
    return B[B[a].parent].left;
  }
  if (B[B[a].parent].right != a && B[B[a].parent].right != -1) {
    return B[B[a].parent].right;
  }
  return -1;
}
void pr(int a) {
  printf("node %d: ", a);
  printf("parent = %d, ", B[a].parent);
  printf("sibling = %d, ", pick(a));

  int c;
  c = 0;
  if (B[a].left != -1) c++;
  if (B[a].right != -1) c++;
  printf("degree = %d, ", c);

  printf("depth = %d, ", D[a]);
  printf("height = %d, ", C[a]);

  if (B[a].parent == -1) {
    printf("root");
    printf("\n");
  } else if (B[a].left == -1 && B[a].right == -1) {
    printf("leaf");
    printf("\n");
  } else {
    printf("internal node");
    printf("\n");
  }
}
