#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
#define NIL -1

int parent[MAX],left[MAX],right[MAX];
int n,D[MAX],H[MAX];

void setDepth(int u,int d){
  if(u== NIL) return;
  D[u]=d;
  setDepth(left[u],d+1);
  setDepth(right[u],d+1);
}

int setHeight(int u){
  int h1=0,h2=0;
  if(left[u]!=NIL){
  h1 = setHeight(left[u])+1;}
  if(right[u]!=NIL){
  h2 = setHeight(right[u])+1;}
  return H[u]=(h1>h2 ? h1 : h2);
}

int getSibling(int u){
  if(parent[u]==NIL)return NIL;
  if(left[parent[u]] != u && left[parent[u]] != NIL){
  return left[parent[u]];}
  if(right[parent[u]] != u && right[parent[u]] != NIL){
  return right[parent[u]];}
  return NIL;
}

void print(int u){
  int degree =0;
  printf("node %d: ",u);
  printf("parent = %d, ",parent[u]);
  printf("sibling = %d, ",getSibling(u));
  if(left[u]!=NIL)degree++;
  if(right[u]!=NIL)degree++;
  printf("degree = %d, ",degree);
  printf("depth = %d, ",D[u]);
  printf("height = %d, ",H[u]);

  if(parent[u]==NIL){
    printf("root\n");
  }
  else if (left[u]==NIL && right[u]==NIL){
    printf("leaf\n");
  }
  else printf("internal node\n");
}

int main(){
  int i,v,l,r,root=0;
  scanf("%d",&n);

  for (i=0;i<n;i++) parent[i]=NIL;

for (i=0;i<n;i++) {
  scanf("%d %d %d",&v,&l,&r);
  left[v]=l;
  right[v]=r;
  if (l!=NIL) parent[l]=v;
  if (r!=NIL) parent[r]=v;
}

for (i=0;i<n;i++) if(parent[i] == NIL) root=i;

setDepth(root,0);
setHeight(root);

for (i=0;i<n;i++) print(i);

return 0;
}
