#include<stdio.h>
#define MAX 5000
#define NIL -1

struct Node_struct{int p, l, r;}; 
typedef struct Node_struct Node;
Node A[MAX];
int D[MAX], H[MAX];

int Sibling(int i){
  if(A[i].p == NIL) return NIL;
  if(A[A[i].p].l != i && A[A[i].p].l != NIL) return A[A[i].p].l;
  if(A[A[i].p].r != i && A[A[i].p].r != NIL) return A[A[i].p].r;
  return NIL;
}

void print(int u){
  int i, c, degree = 0;
  printf("node %d: parent = %d, sibling = %d, ", u, A[u].p, Sibling(u));
  if(A[u].l != NIL) degree += 1;
  if(A[u].r != NIL) degree += 1;
  printf("degree = %d, ", degree);
  printf("depth = %d, ", D[u]);
  printf("height = %d, ", H[u]);
  if(A[u].p == NIL) printf("root\n");
  else if(A[u].l == NIL && A[u].r == NIL) printf("leaf\n");
  else printf("internal node\n");
}

void calcDepth(int u, int p){
  if(u == NIL) return;
  D[u] = p;
  calcDepth(A[u].l, p + 1);
  calcDepth(A[u].r, p + 1);
}

int Height(int u) {
  int h1 = 0, h2 = 0;
  if(A[u].l != NIL) h1 = Height(A[u].l) + 1;
  if(A[u].r != NIL) h2 = Height(A[u].r) + 1;
  if(h1 >= h2) return H[u] = h1;
  else return H[u] = h2;
}

int main(){
  int i, n, root;
  int id, left, right;
  scanf("%d", &n);
  for(i = 0 ; i < n ; i++) A[i].p = A[i].l = A[i].r = NIL;
  for(i = 0 ; i < n ; i++){
    scanf("%d %d %d", &id, &left, &right);
    A[id].l = left;
    if(left != NIL) A[left].p = id;
    A[id].r = right;
    if(right != NIL) A[right].p = id;
  }
  for(i = 0 ; i < n ; i++) if(A[i].p == NIL) root = i;
  calcDepth(root, 0);
  Height(root);
  for(i = 0 ; i < n ; i++) print(i);
}
