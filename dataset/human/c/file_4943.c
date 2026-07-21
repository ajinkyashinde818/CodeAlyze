#include<stdio.h>
#define MAX 10000
#define NIL -1

struct Node{
  int parent,left,right;
};

  struct Node A[MAX];
int n,d[MAX],h[MAX];

void Depth(int x,int y){
  if(x==NIL)return;
  d[x]=y;
  Depth(A[x].left,y+1);
  Depth(A[x].right,y+1);
}

int Height(int x){
  int h1=0,h2=0;
  if(A[x].left!=NIL)h1=Height(A[x].left)+1;
  if(A[x].right!=NIL)h2=Height(A[x].right)+1;

  return h[x]=(h1>h2 ? h1:h2);
}

int Sibling(int x){
  if(A[x].parent==NIL)return NIL;
  if(A[A[x].parent].left!=x && A[A[x].parent].left!=NIL)return A[A[x].parent].left;
  if(A[A[x].parent].right!=x && A[A[x].parent].right!=NIL)return A[A[x].parent].right;

  return NIL;
}
void Print(int x){
  printf("node %d: ",x);
  printf("parent = %d, ",A[x].parent);
  printf("sibling = %d, ",Sibling(x));
  int deg=0;

  if(A[x].left!=NIL)deg++;
  if(A[x].right!=NIL)deg++;
  printf("degree = %d, ",deg);
  printf("depth = %d, ",d[x]);
  printf("height = %d, ",h[x]);

  if(A[x].parent == NIL)printf("root\n");
  else if(A[x].left==NIL && A[x].right==NIL)printf("leaf\n");
  else printf("internal node\n");

}

int main(){
  int v,l,r,root=0,i;

  scanf("%d",&n);

  for(i=0;i<n;i++)A[i].parent=NIL;

  for(i=0;i<n;i++){
    scanf("%d %d %d",&v,&l,&r);
    A[v].left=l;
    A[v].right=r;
    if(l!=NIL)A[l].parent=v;
    if(r!=NIL)A[r].parent=v;
  }

  for(i=0;i<n;i++)if(A[i].parent==NIL)root=i;

  Depth(root, 0);
  Height(root);

  for(i=0;i<n;i++)Print(i);

  return 0;
}
