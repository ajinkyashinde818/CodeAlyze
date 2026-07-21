#include<stdio.h>
#define MAX 25
#define NIL -1
struct Node_struct{int p,l,r,sib;}; /*p: 親(parent), l: 一番左の子(left child), r:右の兄弟(right sibling)*/
typedef struct Node_struct Node;
Node T[MAX];
int D[MAX];
int deg[MAX];
int H[MAX];

void print(int u){
  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",u,T[u].p,T[u].sib,deg[u],D[u],H[u]);

  if(D[u]==0)printf("root");
  else if(T[u].l==NIL && T[u].r==NIL)printf("leaf");
  else printf("internal node");
  
  printf("\n");
  
}

void calcDepth(int u, int p){
  D[u] = p;
  if(T[u].r!=NIL)calcDepth(T[u].r,p+1);
  if(T[u].l!=NIL)calcDepth(T[u].l,p+1);
}

void calcHeight(int u){
  if(T[u].l==NIL && T[u].r==NIL){H[u]=0;return;}

  if(T[u].l!=NIL)calcHeight(T[u].l);
  if(T[u].r!=NIL)calcHeight(T[u].r);
  
  if(H[T[u].l]<H[T[u].r])H[u]=H[T[u].r]+1;
  else H[u]=H[T[u].l]+1;
  return;
}

int main(){
  int i,j;
  int n;
  int id,child;
  int root=NIL;
  scanf("%d", &n);
  for(i=0;i<n;i++)T[i].p=T[i].l=T[i].r=T[i].sib=NIL;
  
  for(i=0; i<n; i++){
    scanf("%d", &id);
    for(j=0;j<2;j++){ //子を入力する (input children)
      scanf("%d", &child);
      if(child!=NIL)deg[id]++;
      T[child].p = id;
      if(j == 0) T[id].l = child; //idの一番左の子 (the most left child of id)
      else T[id].r = child; //左の兄弟に繋げる (connect to left sibling)
      if(deg[id]==2)T[T[id].l].sib=child,T[T[id].r].sib=T[id].l;
    }
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
