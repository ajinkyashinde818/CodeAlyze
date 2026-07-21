#include<stdio.h>
#define MAX 10000
#define NIL -1

struct Node{
  int parent,left,right;
};
struct Node T[MAX];
int n,D[MAX],H[MAX];

void depth(int u,int p){
  if(u==NIL)return;
  D[u]=p;
  depth(T[u].right,p+1);
  depth(T[u].left,p+1);
}

int height(int u){
  int h1=0,h2=0;
  if(T[u].left!=NIL)
    h1=height(T[u].left)+1;
  if(T[u].right!=NIL)
    h2=height(T[u].right)+1;
  return H[u]=(h1>h2?h1:h2);
}

int sibling(int u){
  if(T[u].parent==NIL)return NIL;
  if(T[T[u].parent].left!=u&&T[T[u].parent].left!=NIL)
    return T[T[u].parent].left;
  if(T[T[u].parent].right!=u&&T[T[u].parent].right!=NIL)
    return T[T[u].parent].right;
  return NIL;
}
void print(int u){
  int i,c;
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].parent);
  printf("sibling = %d, ",sibling(u));
  int g=0;
  if(T[u].left!=NIL)g++;
  if(T[u].right!=NIL)g++;
  printf("degree = %d, ",g);
  printf("depth = %d, ",D[u]);
  printf("height = %d, ",H[u]);

  if(T[u].parent==NIL)printf("root\n");
  else if(T[u].left==NIL&&T[u].right==NIL)printf("leaf\n");
  else printf("internal node\n");
}
int main(){
  int i,v,l,r,t,d,c,j;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    T[i].parent=NIL;
  }
  for(i=0;i<n;i++){
    scanf("%d%d%d",&v,&l,&r);
    T[v].left=l;
    T[v].right=r;
    if(l!=NIL)T[l].parent=v;
    if(r!=NIL)T[r].parent=v;
  }

  for(i=0;i<n;i++){
    if(T[i].parent==NIL)r=i;
  }

  depth(r,0);
  height(r);

  for(i=0;i<n;i++) print(i);

  return 0;
}
