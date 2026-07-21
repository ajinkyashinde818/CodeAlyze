#include<stdio.h>
#define MAX 10000
#define NIL -1
void depth(int,int);
void printz(int);
int height(int);
int sibling(int);
struct Node{int parent,left,right;};
struct Node A[MAX];
int n,X[MAX],Y[MAX];
int main(){
  int i,a,b,c,x;
  scanf("%d",&n);
for(i=0;i<n;i++){
  A[i].parent=NIL;
}
  for(i=0;i<n;i++){
    scanf("%d %d %d",&a,&b,&c);
    A[a].left=b;
      A[a].right=c;
      if(b!=NIL)
	A[b].parent=a;
      if(c!=NIL)
	A[c].parent=a;
  }
  for(i=0;i<n;i++){
    if(A[i].parent==NIL)
      x=i;
  }
  depth(x,0);
  height(x);
  for(i=0;i<n;i++) printz(i);
  return 0;
}

void depth(int x,int y){
  if(x==NIL)
    return;
  X[x]=y;
    depth(A[x].right,y+1);
    depth(A[x].left,y+1);
}

int height(int x){
  int h1=0,h2=0;
    if(A[x].left!=NIL)
      h1=height(A[x].left)+1;
  if(A[x].right!=NIL)
    h2=height(A[x].right)+1;
  return Y[x]=(h1>h2?h1:h2);
}
int sibling(int x){
  if(A[x].parent==NIL)
    return NIL;
  if(A[A[x].parent].left!=x&&A[A[x].parent].left!=NIL)
    return A[A[x].parent].left;
   if(A[A[x].parent].right!=x&&A[A[x].parent].right!=NIL)
    return A[A[x].parent].right;
   return NIL;
}
  
void printz(int x){
int i,y=0;
  printf("node %d: ",x);
  printf("parent = %d, ",A[x].parent);
  printf("sibling = %d, ",sibling(x));
  if(A[x].left!=NIL)
    y++;
  if(A[x].right!=NIL)
    y++;
  printf("degree = %d, ",y);
  printf("depth = %d, ",X[x]);
  printf("height = %d, ",Y[x]);
  if(A[x].parent==NIL)
    printf("root\n");
  else if(A[x].left==NIL&&A[x].right==NIL)
    printf("leaf\n");
  else
    printf("internal node\n");
}
