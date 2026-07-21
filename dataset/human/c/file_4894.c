#include<stdio.h>
#define MAX 25
#define NIL -1
struct node{
  int parent,left,right;
};
struct node T[MAX];
int n,D[MAX],H[MAX];

void depth(int u,int d){
  if(u==NIL) return;
  D[u]=d;
  if(T[u].left!=NIL) depth(T[u].left,d+1);
  if(T[u].right!=NIL) depth(T[u].right,d+1);
}
int height(int u){
  int h1=0,h2=0;
  if(T[u].left!=NIL) h1=height(T[u].left)+1;
  if(T[u].right!=NIL) h2=height(T[u].right)+1;
  return H[u]=(h1>h2?h1:h2);
}
int sibling(int u){
  if(T[u].parent==NIL) return NIL;
  if(u!=T[T[u].parent].left&&T[T[u].parent].left!=NIL)
    return T[T[u].parent].left;
  if(u!=T[T[u].parent].right&&T[T[u].parent].right!=NIL)
    return T[T[u].parent].right;
  return NIL;
}
void print(int u){
  int deg=0,flag;
  printf("node %d: parent = %d, ",u,T[u].parent);
  printf("sibling = %d, ",sibling(u));
  if(T[u].left!=NIL) deg++;
  if(T[u].right!=NIL) deg++;
  printf("degree = %d, depth = %d, height = %d, ",deg,D[u],H[u]);
  if(T[u].parent==NIL) printf("root\n");
  else if(deg==0) printf("leaf\n");
  else printf("internal node\n");
}

int main(){
  int i,u,l,r,root;
  scanf("%d",&n);
  for(i=0;i<n;i++) T[i].parent=T[i].left=T[i].right=NIL;

  for(i=0;i<n;i++){
    scanf("%d",&u);
    scanf("%d",&l);
    scanf("%d",&r);
    T[u].left=l;
    T[u].right=r;
    if(l!=NIL) T[l].parent=u;
    if(r!=NIL) T[r].parent=u;
  }

  for(i=0;i<n;i++){
    if(T[i].parent==NIL) root=i;
  }

  depth(root,0);
  height(root);
  for(i=0;i<n;i++) print(i);
  return 0;
}
