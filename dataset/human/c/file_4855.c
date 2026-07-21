#include <stdio.h>
#define MAX 10000
#define NIL -1

void setDepth(int, int);
int setHeight(int);
int getSibling(int);
void print(int);

struct node{
  int parent;
  int left;
  int right;
};
struct node T[MAX];

int n, D[MAX], H[MAX];

int main(){
  int n, i, v, l, r, root = 0;

  scanf("%d",&n);
  for(i = 0; i < n; i++){
    T[i].parent = NIL;
    T[i].left = NIL;   /*入力で -1 を入力するから、left と rightを NIL で初期化する必要はないけど、初期化しておく。*/
    T[i].right = NIL;
  }
  for(i = 0; i < n; i++){
    scanf("%d %d %d", &v, &l, &r);
  T[v].left = l;
  T[v].right = r;
  if(l != NIL) T[l].parent = v;
  if(r != NIL) T[r].parent = v;
  }
  for(i = 0; i < n; i++) if(T[i].parent == NIL) root = i;

  setDepth(root, 0);
  setHeight(root);

  for(i = 0; i < n; i++) print(i);

  return 0;
}
void setDepth(int u, int d){
  if(u == NIL) return;
  D[u] = d;
  setDepth(T[u].left, d + 1);
  setDepth(T[u].right, d + 1);
}
int setHeight(int u){
  int h1 = 0, h2 = 0;
  if(T[u].left != NIL) h1 = setHeight(T[u].left) + 1;
  if(T[u].right != NIL) h2 = setHeight(T[u].right) + 1;
  if(h1 > h2) return H[u] = h1;
  else return H[u] = h2;
}
int getSibling(int u){
  if(T[u].parent == NIL) return NIL;
  if(T[T[u].parent].left != u && T[T[u].parent].left != NIL) return T[T[u].parent].left;
  if(T[T[u].parent].right != u && T[T[u].parent].right != NIL) return T[T[u].parent].right;
  return NIL;   /*兄弟が存在しない場合は、-1 だから、NIL を入れる。*/					      
}
void print(int u){
  int degree;
  printf("node %d: ", u);
  printf("parent = %d, ", T[u].parent);
  printf("sibling = %d, ", getSibling(u));
  if(T[u].left != NIL) degree++;
  if(T[u].right != NIL) degree++;
  printf("degree = %d, ", degree);
  printf("depth = %d, ", D[u]);
  printf("height = %d, ", H[u]);

  if(T[u].parent == NIL) printf("root\n");
  else if(T[u].left == NIL && T[u].right == NIL) printf("leaf\n");
  else printf("internal node\n");
}
