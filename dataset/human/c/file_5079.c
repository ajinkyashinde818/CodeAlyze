#include<stdio.h>
#define MAX 10000
#define NIL -1

typedef struct{
  int parent;
  int left;
  int right;
}Node;

Node T[MAX];
int n,D[MAX],H[MAX];

void setDepth(int i,int c){
  if(i==NIL)return;
  D[i]=c;
  setDepth(T[i].left,c+1);
  setDepth(T[i].right,c+1);
}

int setHeight(int i){
  int h1=0,h2=0;
  if(T[i].left!=NIL)h1=setHeight(T[i].left)+1;
  if(T[i].right!=NIL)h2=setHeight(T[i].right)+1;
  return H[i]=(h1>h2?h1:h2);
}

int getSibling(int i){
  if(T[i].parent==NIL)return NIL;
  if(T[T[i].parent].left!=i && T[T[i].parent].left!=NIL)
    return T[T[i].parent].left;
  if(T[T[i].parent].right!=i && T[T[i].parent].right!=NIL)
    return T[T[i].parent].right;
  return NIL;
}

void display(int i){
  printf("node %d: ",i);
  printf("parent = %d, ",T[i].parent);
  printf("sibling = %d, ",getSibling(i));
  int deg=0;
  if(T[i].left != NIL)deg++;
  if(T[i].right != NIL)deg++;
  printf("degree = %d, ",deg);
  printf("depth = %d, ",D[i]);
  printf("height = %d, ",H[i]);

  if(T[i].parent==NIL)printf("root\n");
  else if(T[i].left==NIL && T[i].right==NIL)printf("leaf\n");
  else {printf("internal node\n");}
}

int main(){
  int v,l,r,i,root=0;
  scanf("%d",&n);

  for(i=0;i<n;i++)T[i].parent=NIL;

  for(i=0;i<n;i++){
    scanf("%d %d %d",&v,&l,&r);
    T[v].left=l;
    T[v].right=r;
    if(l!=NIL)T[l].parent=v;
    if(r!=NIL)T[r].parent=v;
  }

  for(i=0;i<n;i++)if(T[i].parent==NIL)root=i;

  setDepth(root,0);
  setHeight(root);

  for(i=0;i<n;i++)display(i);

  return 0;

}
