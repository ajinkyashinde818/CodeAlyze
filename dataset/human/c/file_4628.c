#include<stdio.h>
#define MAX 100005
#define NIL -1
struct Node_struct{int p, l, r, sib;}; /*p: 親(parent), l: 一番左の子(left child), r:右の兄弟(right sibling)*/
typedef struct Node_struct Node;
Node T[MAX];
int D[MAX];
int H[MAX];

void print(int u){
  int i, c, degree=0;
  if(T[u].l!=NIL) degree++;
  if(T[u].r!=NIL) degree++;
  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", u, T[u].p, T[u].sib, degree, D[u], H[u]);

  if(T[u].p==NIL) printf("root\n");
  else if(T[u].l==NIL && T[u].r==NIL) printf("leaf\n");
  else printf("internal node\n");
}

void calcDepth(int u, int p){
  D[u] = p;
  //printf("id=%d left=%d right=%d\n",u,T[u].l,T[u].r);
  if(T[u].l!=NIL) calcDepth(T[u].l, p+1);
  if(T[u].r!=NIL) calcDepth(T[u].r, p+1);
}

int calcHeight(int u, int p){
    int left, right;
    if(T[u].l!=NIL) left = calcHeight(T[u].l, p+1);
    else left = p;
    if(T[u].r!=NIL) right = calcHeight(T[u].r, p+1);
    else right = p;
    if(left>right) return left;
    else return right;
}

int main(){
  int i;
  int n;
  int id, left, right;
  int root = NIL;
  scanf("%d", &n);
  for(i=0; i<n; i++) T[i].p = T[i].l = T[i].r = T[i].sib = NIL;

  for(i=0; i<n; i++){
    scanf("%d", &id);
    scanf("%d%d", &left,&right);
    T[left].p = id;
    T[right].p = id;
    T[id].l = left; //idの一番左の子 (the most left child of id)
    T[id].r = right; //左の兄弟に繋げる (connect to left sibling)
    T[left].sib = right;
    T[right].sib = left;
  }

  //根を求める (find the root)
  for(i=0; i<n; i++){
    if(T[i].p == -1) root = i;
  }

  //それぞれのノードの深さを求める (find depth of each node)
  calcDepth(root, 0);

  //出力 (output)
  for(i=0; i<n; i++){
      H[i] = calcHeight(i, 0);
      print(i);
  }

  return 0;
}
