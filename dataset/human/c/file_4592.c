#include<stdio.h>
#define NIL -1
#define MAX 10000
typedef struct node {
  int parent;
  int l;
  int r;
} Node;
Node T[MAX];
int n,D[MAX],H[MAX];
void Depth(int u,int d){
  if(u == NIL)return;
  D[u]=d;
  Depth(T[u].l,d+1);
  Depth(T[u].r,d+1);
}
int Height(int u){
  int h1=0,h2=0;
  if(T[u].l!=NIL){
      h1=Height(T[u].l)+1;
  }
  if(T[u].r!=NIL){
      h2=Height(T[u].r)+1;
  }
  if(h1>h2){
    return H[u]=(h1);
  }
  else return H[u]=(h2);
}
int Sibling(int u){
  if(T[u].parent==NIL){
    return NIL;
  }
  if(T[T[u].parent].l != u && T[T[u].parent].l != NIL){
    return T[T[u].parent].l;
  }
  if(T[T[u].parent].r != u && T[T[u].parent].r != NIL){
    return T[T[u].parent].r;
  }
  return NIL;
}
void print(int u){
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].parent);
  printf("sibling = %d, ",Sibling(u));
  int deg=0;
  if(T[u].l!=NIL)deg++;
  if(T[u].r!=NIL)deg++;
  printf("degree = %d, ",deg);
  printf("depth = %d, ",D[u]);
  printf("height = %d, ", H[u]);

  if(T[u].parent==NIL){
    printf("root\n");
  }
  else if(T[u].l==NIL && T[u].r==NIL){
    printf("leaf\n");
  }
  else{
    printf("internal node\n");
  }
}
int main(){
  int v,l,r,root=0;
  scanf("%d",&n);
  int i;
  for(i=0;i<n;i++){
    T[i].parent=NIL;
  }
  for(i=0;i<n;i++){
    scanf("%d %d %d",&v,&l,&r);
    T[v].l=l;
    T[v].r=r;
    if(l!=NIL)T[l].parent=v;
    if(r!=NIL)T[r].parent=v;
  }
  for(i=0;i<n;i++){
    if(T[i].parent ==NIL)root=i;
  }
    Depth(root,0);
    Height(root);
    for(i=0;i<n;i++)print(i);
    return 0;

}
