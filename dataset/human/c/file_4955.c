#include<stdio.h>
#define MAX 10000
#define NIL -1
struct Node_struct{int p, l, r;}; /*p: 親(parent), l: 一番左の子(left child), r:右の兄弟(right sibling)*/
typedef struct Node_struct Node;
Node T[MAX];
 int D[MAX],H[MAX];

int max(int a,int b){
  if(a>b) return a;
  else return b;
}

int getSibling(int u){
  if(T[u].p==NIL) return NIL;
  if(T[T[u].p].l!=u && T[T[u].p].l!=NIL) return T[T[u].p].l;
  if(T[T[u].p].r!=u && T[T[u].p].r!=NIL) return T[T[u].p].r;
  return NIL;
}

void print(int u){
  int deg=0;
  if(T[u].l!=NIL) deg++;
  if(T[u].r!=NIL) deg++;
  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", u, T[u].p,getSibling(u),deg,D[u],H[u]);
  if(T[u].p==NIL) printf("root\n");
  else if(T[u].l==NIL && T[u].r==NIL) printf("leaf\n");
  else printf("internal node\n");
}

void calcDepth(int u, int p){
  if(u==NIL) return ;
  D[u] = p;
  if(T[u].r!=NIL) calcDepth(T[u].r,p+1);
  if(T[u].l!=NIL) calcDepth(T[u].l,p+1);
}

int calcHeight(int u){
  int h1=0,h2=0;
  if(T[u].l!=NIL) h1=calcHeight(T[u].l)+1;
  if(T[u].r!=NIL) h2=calcHeight(T[u].r)+1;
  return H[u]=max(h1,h2);
}




int main(){
  int i, j, k;
  int n;
  int id,l,r;
  int root = 0;
  scanf("%d", &n);
  for(i=0; i<n; i++) T[i].p=NIL;
  
  for(i=0; i<n; i++){
    scanf("%d%d%d", &id,&l,&r);
      T[id].l = l;
      T[id].r=r;
      if(l!=NIL) T[l].p = id;
      if(r!=NIL) T[r].p = id;
  }

  //根を求める (find the root)
  for(i=0; i<n; i++){
    if(T[i].p == -1) root = i;
  }
  
  //それぞれのノードの高さ深さを求める (find depth of each node)
  calcHeight(root);
  calcDepth(root, 0);

  //出力 (output)
  for(i=0; i<n; i++) print(i);
  
  return 0;
}
