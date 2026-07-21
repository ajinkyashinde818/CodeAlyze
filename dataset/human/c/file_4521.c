#include <stdio.h>
#define N 25
#define NIL -1

struct Node{
  int parent,left,right;
};
struct Node T[10000];
int n,D[10000],H[10000];
int setHeight(int);
void setDepth(int,int);
//節点uの兄弟を返す
int brosend(int);
void print(int);

int main(){
  int n,i,v,l,r;
  int root=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    T[i].parent=NIL;
  for(i=0;i<n;i++){
    scanf("%d %d %d",&v,&l,&r);
    T[v].left=l;
    T[v].right=r;
    if(l!=NIL)T[l].parent=v;
    if(r!=NIL)T[r].parent=v;
  }
  for(i=0;i<n;i++){
    if(T[i].parent==NIL)
      root=i;
  }
  setDepth(root,0);
  setHeight(root);
  for(i=0;i<n;i++)
    print(i);
  return 0;
}
int setHeight(int k){
  int h1=0,h2=0;
  if(T[k].left!=NIL)
    h1=setHeight(T[k].left)+1;
  if(T[k].right!=NIL)
    h2=setHeight(T[k].right)+1;
  return H[k]=(h1>h2?h1:h2);
}
void setDepth(int k,int g){
  if(k==NIL) return;
  D[k]=g;
  setDepth(T[k].left,g+1);
  setDepth(T[k].right,g+1);
}
int brosend(int k){
  if(T[k].parent==NIL)
    return NIL;
  if(T[T[k].parent].left!=k&&T[T[k].parent].left!=NIL)
    return T[T[k].parent].left;
  if(T[T[k].parent].right!=k&&T[T[k].parent].right!=NIL)
    return T[T[k].parent].right;
  return NIL;
}
void print(int k){
  printf("node %d: ",k);
  printf("parent = %d, ",T[k].parent);
  printf("sibling = %d, ",brosend(k));
  int deg=0;
  if(T[k].left!=NIL)deg++;
  if(T[k].right!=NIL)deg++;
  printf("degree = %d, ",deg);
  printf("depth = %d, ",D[k]);
  printf("height = %d, ",H[k]);

  if(T[k].parent==NIL){
    printf("root\n");
  }
  else if(T[k].left==NIL&&T[k].right==NIL){
    printf("leaf\n");
  }
  else {
    printf("internal node\n");
  }
}
