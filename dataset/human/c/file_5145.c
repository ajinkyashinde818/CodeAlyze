#include<stdio.h>
#define MAX 100005
#define NIL -1
struct Node_struct{int p, l, r;}; /*p: 親(parent), l: 一番左の子(left child), r:右の兄弟(right sibling)*/
typedef struct Node_struct Node;
Node T[MAX];
int D[MAX];
int H[MAX];

void print(int u){
  int i, c, deg=0;
  printf("node %d: parent = %d, ", u, T[u].p);
  printf("sibling = ");
  if(T[u].p==NIL) printf("%d, ",NIL);
  else if(T[T[u].p].l != u && T[T[u].p].l != NIL) printf("%d, ",T[T[u].p].l);
  else if(T[T[u].p].r != u && T[T[u].p].r != NIL) printf("%d, ",T[T[u].p].r);
  else printf("%d, ",NIL);
  if(T[u].l!=NIL) deg++;
  if(T[u].r!=NIL) deg++;
  printf("degree = %d, ",deg);
  printf("depth = %d, height = %d, ",D[u],H[u]);

  if(T[u].p==NIL) printf("root\n");
  else if(T[u].l==NIL&&T[u].r==NIL) printf("leaf\n");
  else printf("internal node\n");

}

void calcDepth(int u, int p){
  D[u] = p;
  if(T[u].l!=NIL) calcDepth(T[u].l,p+1);
  if(T[u].r!=NIL) calcDepth(T[u].r,p+1);
}

int calcHeight(int u){
  int a=0,b=0;
  if(T[u].l!=NIL){
    a=calcHeight(T[u].l)+1;
  }
  if(T[u].r!=NIL){
    b=calcHeight(T[u].r)+1;
  }
  if(a>b){
    H[u]=a;
    return H[u];
  }
  else{
    H[u]=b;
    return H[u];
  }
}

int main(){
  int i, j, k;
  int n;
  int id, child1,  child2;
  int root = NIL;
  scanf("%d", &n);
  for(i=0; i<n; i++) T[i].p = T[i].l = T[i].r = NIL;

  for(i=0; i<n; i++){
    scanf("%d", &id);
    scanf("%d %d", &child1,&child2);
      T[id].l = child1;
      T[id].r = child2;
      if(child1!=NIL) T[child1].p = id; //idの一番左の子 (the most left child of id)
      if(child2!=NIL) T[child2].p = id; //左の兄弟に繋げる (connect to left sibling)
      //sib = child;//次の子供の左の兄弟 (the left sibling of the next child)
    }

  //根を求める (find the root)
  for(i=0; i<n; i++){
    if(T[i].p == -1) root = i;
  }

  //それぞれのノードの深さを求める (find depth of each node)
  calcDepth(root, 0);
  calcHeight(root);

  //出力 (output)
  for(i=0; i<n; i++) print(i);

  return 0;
}
