#include<stdio.h>
#define MAX 100005
#define NIL -1
struct Node_struct{int p, l, r;}; /*p: 親(parent), l: 左の子(left child), r:右の兄弟(right sibling)*/

typedef struct Node_struct Node;

Node T[MAX];
int D[MAX],H[MAX],n;

void setDepth(int u, int p){
  if(u==NIL)return;
  D[u] = p;
  setDepth(T[u].l,p+1);
  setDepth(T[u].r,p+1);
}

int setHeight(int u){
  int h1=0,h2=0;
  if(T[u].l!=NIL)h1=setHeight(T[u].l)+1;
  if(T[u].r!=NIL)h2=setHeight(T[u].r)+1;
  return H[u]=(h1>h2 ? h1:h2);
}

int getSibling(int u){
  if(T[u].p==NIL)return NIL;
  if(T[T[u].p].l!=u && T[T[u].p].l!=NIL)return T[T[u].p].l;
  if(T[T[u].p].r!=u && T[T[u].p].r!=NIL)return T[T[u].p].r;
  return NIL;
}

void print(int u){
  int i, c;
  printf("node %d: parent = %d, sibling = %d, ", u,T[u].p,getSibling(u));
  int deg=0;
  if(T[u].l!=NIL)deg++;
  if(T[u].r!=NIL)deg++;
  printf("degree = %d, depth = %d, height = %d, ",deg,D[u],H[u]);


  if(T[u].p==-1) printf("root");
  else if(T[u].l==NIL && T[u].r==NIL) printf("leaf");
  else printf("internal node");

  printf("\n");

}


int main(){
  int i,v,left,right,root = 0;
  scanf("%d", &n);
  for(i=0; i<n; i++) T[i].p = NIL;
  for(i=0;i<n;i++){
    scanf("%d %d %d",&v,&left,&right);
    T[v].l=left;
    T[v].r=right;
    if(left!=NIL)T[left].p=v;
    if(right!=NIL)T[right].p=v;
  }


  //根を求める (find the root)
  for(i=0; i<n; i++){
    if(T[i].p == NIL) root = i;
  }

  //それぞれのノードの深さを求める (find depth of each node)
  setDepth(root, 0);
  setHeight(root);
  //出力 (output)
  for(i=0; i<n; i++) print(i);

  return 0;
}
