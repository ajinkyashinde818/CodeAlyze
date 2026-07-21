#include<stdio.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define REPR(i,n) for(int i=n-1;i>=0;i--)
#define IFY 2000000000
#define MAX 10000
#define NIL -1
struct Node {int parent,left,right;};
Node T[MAX];
int n,D[MAX],H[MAX];
void setdepth(int u,int d){
  if(u==NIL) return;
  D[u]=d;
  setdepth(T[u].left,d+1);
  setdepth(T[u].right,d+1);
}
int setheight(int u){
  int h1=0,h2=0;
  if(T[u].left!=NIL) h1=setheight(T[u].left)+1;
  if(T[u].right!=NIL) h2=setheight(T[u].right)+1;
  return H[u]=(h1>h2?h1:h2);
}
int getsibling(int u){
  if(T[u].parent==NIL) return NIL;
  if(T[T[u].parent].left!=NIL&&T[T[u].parent].left!=u) return T[T[u].parent].left;
  if(T[T[u].parent].right!=NIL&&T[T[u].parent].right!=u) return T[T[u].parent].right;
  return NIL;
}
void print(int u){
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].parent);
  printf("sibling = %d, ",getsibling(u));
  int deg=0;
  if(T[u].left!=NIL) deg++;
  if(T[u].right!=NIL) deg++;
  printf("degree = %d, ",deg);
  printf("depth = %d, ",D[u]);
  printf("height = %d, ",H[u]);
  if(T[u].parent==NIL) printf("root\n");
  else if(T[u].left==NIL&&T[u].right==NIL) printf("leaf\n");
  else printf("internal node\n");
}
int main(){
  int root=0,v,l,r;
  scanf("%d",&n);
  REP(i,n) T[i].parent=NIL;
  REP(i,n){
    scanf("%d %d %d",&v,&l,&r);
    T[v].left=l;
    T[v].right=r;
    if(l!=NIL) T[l].parent=v;
    if(r!=NIL) T[r].parent=v;
  }
  REP(i,n) if(T[i].parent==NIL) root=i;
  setdepth(root,0);
  setheight(root);
  REP(i,n) print(i);
  return 0;
}
