#include<stdio.h>
#define MAX 1000
#define NIL -1
struct Node_struct{int p, l, r;}; 
typedef struct Node_struct Node;
Node T[MAX];
int D[MAX], H[MAX];

int Sibling(int u){
  if(T[u].p == NIL) return NIL;
  if(T[T[u].p].l != u && T[T[u].p].l != NIL) return T[T[u].p].l;
  if(T[T[u].p].r != u && T[T[u].p].r != NIL) return T[T[u].p].r;
  return NIL;
}

void print(int u){
  int i, c, degree = 0;
  printf("node %d: parent = %d, sibling = %d, ", u, T[u].p, Sibling(u));
  if(T[u].l != NIL) degree += 1;
  if(T[u].r != NIL) degree += 1;
  
  printf("degree = %d, ", degree);
  printf("depth = %d, ", D[u]);
  printf("height = %d, ", H[u]);
  
  if(T[u].p == NIL) printf("root\n");
  else if(T[u].l == NIL && T[u].r == NIL) printf("leaf\n");
  else printf("internal node\n");
}

void calcDepth(int u, int p){
  if(u == NIL) return;
  D[u] = p;
  calcDepth(T[u].l, p + 1);
  calcDepth(T[u].r, p + 1);
}

int Height(int u) {
  int hei1 = 0, hei2 = 0;
  
  if(T[u].l != NIL) hei1 = Height(T[u].l) + 1;
  if(T[u].r != NIL) hei2 = Height(T[u].r) + 1;

  if(hei1 >= hei2) return H[u] = hei1;
  else return H[u] = hei2;
}

int main(){
  int i, n, root;
  int id, left, right;
  
  scanf("%d", &n);
  for(i = 0; i < n; i++) T[i].p = T[i].l = T[i].r = NIL;
  
  for(i = 0; i < n; i++) {
    scanf("%d%d%d", &id, &left, &right);
    
    T[id].l = left;
    if(left != NIL) T[left].p = id;
    
    T[id].r = right;
    if(right != NIL) T[right].p = id;
  }
  for(i = 0; i < n; i++){
    if(T[i].p == NIL) root = i;
  }
  
  //それぞれのノードの深さを求める (find depth of each node)
  calcDepth(root, 0);
  Height(root);
  
  //出力 (output)
  for(i = 0; i < n; i++) print(i);

  return 0;

}
