#include<stdio.h>
#include<stdlib.h>
#define MAX 1000000
#define NIL -1

struct Node{
  int parent;
  int left;
  int right;
};
struct Node A[MAX];
int n,B[MAX],C[MAX];

int getSibling(int s){
  if(A[s].parent==NIL)return NIL;
  if(A[A[s].parent].left!=s&&A[A[s].parent].left!=NIL)return A[A[s].parent].left;
  if(A[A[s].parent].right!=s&&A[A[s].parent].right!=NIL)return A[A[s].parent].right;
 return NIL;
}
 
int setHeight(int x){
  int h1=0,h2=0;
  if(A[x].left!=NIL) h1=setHeight(A[x].left)+1;
  if(A[x].right!=NIL) h2=setHeight(A[x].right)+1;
  return C[x]=(h1>h2?h1:h2);
}
 

 void setDepth(int x,int y){
  if(x==NIL)return;
  B[x]=y;
  setDepth(A[x].left,y+1);
  setDepth(A[x].right,y+1);
}
 
void print(int x){
  int i,c;
  printf("node %d: ",x);
  printf("parent = %d, ",A[x].parent);
  printf("sibling = %d, ",getSibling(x));
  
  int deg=0;
  if(A[x].left!=NIL)deg++;
  if(A[x].right!=NIL)deg++;
  
  printf("degree = %d, ",deg);
  printf("depth = %d, ",B[x]);
  printf("height = %d, ",C[x]);
 
  if(A[x].parent==NIL)printf("root\n");
  else if(A[x].left==NIL&&A[x].right==NIL) printf("leaf\n");
  else  printf("internal node\n");
}
 
int main(){
 
  int x,y,z,root=0,i;
 
  scanf("%d",&n);
  for(i=0;i<n;i++){
    A[i].parent=NIL;
  }
 
  for(i=0;i<n;i++){
     scanf("%d",&x);
     scanf("%d",&y);
     scanf("%d",&z);
     A[x].left=y;
     A[x].right=z;
     if(y!=NIL)A[y].parent=x;
     if(z!=NIL)A[z].parent=x;
  }
  for(i=0;i<n;i++){
    if(A[i].parent==NIL)root=i;
  }
 
  setDepth(root,0);
  setHeight(root);
  for(i=0;i<n;i++)print(i);
 
  return 0;
}
