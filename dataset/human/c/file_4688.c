#include <stdio.h>

#define MAX 10000
#define NIL -1

typedef struct { int parent, left, right;} Node;

Node T[MAX];
int n, D[MAX], H[MAX];

void setDepth(int u,int d) {
  if(u == NIL) return;
  D[u] = d;
  setDepth(T[u].left, d+1);
  setDepth(T[u].right,d+1);
}

int setHeight(int u) {
  int h1 = 0, h2 = 0;
  if(T[u].left != NIL)
    h1 = setHeight(T[u].left) + 1;
  if(T[u].right != NIL)
    h2 = setHeight(T[u].right) + 1;
  return H[u] = (h1 > h2 ? h1 : h2);
}

int main(void) {
  int c=0, v, l, r, root = 0;
  scanf("%d",&n);
  for(int i=0;i<n;i++) T[i].parent = NIL;
  for(int i=0;i<n;i++) {
    scanf("%d %d %d",&v,&l,&r);
    T[v].left  = l;
    T[v].right = r;
    if(l != NIL) T[l].parent = v;
    if(r != NIL) T[r].parent = v;
  }

  for(int i=0; i<n; i++)
  if(T[i].parent == NIL) root = i;

  setDepth(root,0);
  setHeight(root);

  for(int i=0;i<n;i++){
    printf("node %d: ",i);
    printf("parent = %d, ",T[i].parent);

    if( T[i].parent == NIL ){
      printf("sibling = %d, ",NIL);
      c++;
    }
  else if(T[T[i].parent].left != i && T[T[i].parent].left != NIL ){
    printf("sibling = %d, ",T[T[i].parent].left);
    c++;
  }
    else if(T[T[i].parent].right != i && T[T[i].parent].right != NIL ){
      printf("sibling = %d, ",T[T[i].parent].right);
      c++;
    }
  else {
    printf("sibling = %d, ",NIL);
  }
    int deg = 0;
    if(T[i].left  != NIL) deg++;
    if(T[i].right != NIL) deg++;
    printf("degree = %d, ",deg);
    printf("depth = %d, ",D[i]);
    printf("height = %d, ",H[i]);

    if(T[i].parent == NIL) {
      printf("root\n");
    } else if(T[i].left == NIL && T[i].right == NIL) {
      printf("leaf\n");
    } else {
      printf("internal node\n");
    }
  }
  return 0;
}
