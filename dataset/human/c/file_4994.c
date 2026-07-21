#include <stdio.h>
#include <stdlib.h>
#define N 100005
#define NIL -1
struct Node{
  int p,l,r;
};
struct Node T[N];
int n,U[N],A[N];
void setD(int u,int w){
  if(u==NIL) return;
  U[u]=w;
  setD(T[u].l,w+1);
  setD(T[u].r,w+1);
}
int setH(int u){
  int t=0,y=0;
  if(T[u].l!=NIL)
    t=setH(T[u].l)+1;
  if(T[u].r!=NIL)
    y=setH(T[u].r)+1;
  return A[u]=(t>y?t:y);
}
int getS(int u){
  if(T[u].p==NIL)  return NIL;
  if(T[T[u].p].l!=u&&T[T[u].p].l!=NIL)  return T[T[u].p].l;
  if(T[T[u].p].r!=u&&T[T[u].p].r!=NIL)  return T[T[u].p].r;
  return NIL;
}
void print(int u){
  int i,c;
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].p);
  printf("sibling = %d, ",getS(u));
  int deg=0;
  if(T[u].l!=NIL)    deg++;
  if(T[u].r!=NIL)    deg++;
  printf("degree = %d, ",deg);
  printf("depth = %d, ",U[u]);
  printf("height = %d, ",A[u]);
  if(T[u].p==NIL)
    printf("root\n"); 
  else if(T[u].l==NIL&&T[u].r==NIL)
    printf("leaf\n");
  else
    printf("internal node\n");
}
int main(){
  int a,b,c,root=0,i;
  scanf("%d",&n);
  for(i=0;i<=n-1;i++){
    T[i].p=NIL;
  }
  for(i=0;i<=n-1;i++){
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    T[a].l=b;
    T[a].r=c;
    if(b!=NIL)
      T[b].p=a;
    if(c!=NIL)
      T[c].p=a;
  }
  for(i=0;i<=n-1;i++){
    if(T[i].p==NIL)
      root=i;
  }
  setD(root,0);
  setH(root);
  for(i=0;i<=n-1;i++)  print(i);
  return 0;
}
