#include<stdio.h>
#define MAX 100005
#define NIL -1
struct Node_struct{int p, l, r;}; /*p: 親(parent), l: 左の子(left child), r:右の子(right sibling)*/
typedef struct Node_struct Node;
Node T[MAX];
int D[MAX];
int H[MAX];
int S[MAX];
int c=0;

void print(int u){
  int i, s=0;
  printf("node %d: parent = %d, sibling = %d, ", u, T[u].p, S[u]);
  if(T[u].r!=NIL) s++;
  if(T[u].l!=NIL) s++;
  printf("degree = %d, depth = %d, height = %d, ",s,D[u],H[u]);

  if(T[u].p==-1) printf("root\n");
  else if(T[u].l==NIL&&T[u].r==NIL) printf("leaf\n");
  else printf("internal node\n");
  
}

void calcDepth(int u, int p){
  int a=0;
  D[u] = p;
  if(T[u].l!=NIL) calcDepth(T[u].l,p+1);
  if(T[u].r!=NIL) calcDepth(T[u].r,p+1);
}
int calcHeight(int u){
  int rc=0,lc=0;
  int max;
  if(u==NIL) return 0;

  rc=calcHeight(T[u].r)+1;
  lc=calcHeight(T[u].l)+1;

  if(rc < lc) max=lc;
  else max=rc;

  return max;
}

int main(){
  int i, j, k;
  int n;
  int id, sib,r,l;
  int root = NIL;
  scanf("%d", &n);
  for(i=0; i<n; i++){
    T[i].p = T[i].l = T[i].r = NIL;
    H[i]=0;
  }
  
  for(i=0; i<n; i++){
    scanf("%d %d %d", &id, &r, &l);
    if(r!=NIL){
      T[id].r=r;
      T[r].p=id;
      S[r]=l;
    }
    if(l!=NIL){
      T[id].l=l;
      T[l].p=id;
      S[l]=r;
    }
  }

  //根を求める (find the root)
  for(i=0; i<n; i++){
    if(T[i].p == -1) root = i;
  }
  S[root]=-1;
  //それぞれのノードの深さを求める (find depth of each node)
  calcDepth(root, 0);
  //高さ
  for(i=0; i<n; i++) H[i]=calcHeight(i)-1;
  //出力 (output)
  for(i=0; i<n; i++) print(i);
  
  return 0;
}
