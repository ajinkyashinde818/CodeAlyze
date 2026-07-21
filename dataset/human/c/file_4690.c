#include <stdio.h>
#define MAX 10000
#define NIL -1

struct Node {int parent,left,right;};

struct Node A[MAX];
int n,B[MAX],C[MAX];

void Depth(int x,int y){
  if(x==NIL)return;
  B[x]=y;
  Depth(A[x].left,y+1);
  Depth(A[x].right,y+1);
}

int Height(int x){
  int a=0,b=0;
  if(A[x].left!=NIL)
    a=Height(A[x].left)+1;
  if(A[x].right!=NIL)
    b=Height(A[x].right)+1;
  return C[x] = (a>b ? a : b);
}

int kansu(int x){
  if(A[x].parent==NIL)return NIL;
  if(A[A[x].parent].left!=x && A[A[x].parent].left != NIL)
    return A[A[x].parent].left;
  if(A[A[x].parent].right!=x && A[A[x].parent].right!= NIL)
     return A[A[x].parent].right;
  return NIL;
}

void print(int x){
  printf("node %d: ",x);
  printf("parent = %d, ",A[x].parent);
  printf("sibling = %d, ",kansu(x));
  int d = 0;
  if(A[x].left != NIL) d++;
  if(A[x].right != NIL) d++;
  printf("degree = %d, ",d);
  printf("depth = %d, ",B[x]);
  printf("height = %d, ",C[x]);

  if(A[x].parent==NIL){
    printf("root\n");
  }else if (A[x].left== NIL && A[x].right ==NIL){
    printf("leaf\n");
  }else{
    printf("internal node\n");
  }
}
int main(){
  int i,v,l,r,root=0;
  scanf("%d",&n);

  for(i=0;i<n;i++)A[i].parent=NIL;

  for(i=0;i<n;i++){
    scanf("%d%d%d",&v,&l,&r);
    A[v].left=l;
    A[v].right=r;
    if(l!=NIL)A[l].parent=v;
    if(r!=NIL)A[r].parent=v;
  }

  for(i=0;i<n;i++)if(A[i].parent==NIL)root=i;

  Depth(root,0);
  Height(root);

  for(i=0;i<n;i++)print(i);

  return 0;
}
