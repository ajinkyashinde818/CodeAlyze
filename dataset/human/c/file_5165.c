#include<stdio.h>
#include<stdlib.h>
#define MAX 100005
#define NIL -1

struct Node {
  int parent,left,right;
};

struct Node T[MAX];
int n,D[MAX],H[MAX];

void setDepth(int a,int b){
  if(a==NIL)return;
  D[a]=b;
  setDepth(T[a].left,b+1);
  setDepth(T[a].right,b+1);
}

int setHeight(int n){
  int h1=0,h2=0;
  if(T[n].left!=NIL) h1=setHeight(T[n].left)+1;
  if(T[n].right!=NIL) h2=setHeight(T[n].right)+1;
  return H[n]=(h1>h2?h1:h2);
}

int getSibling(int n){
  if(T[n].parent==NIL)return NIL;
  if(T[T[n].parent].left!=n&&T[T[n].parent].left!=NIL)return T[T[n].parent].left;
  if(T[T[n].parent].right!=n&&T[T[n].parent].right!=NIL)return T[T[n].parent].right;
 return NIL;
}


void print(int u){
  int i,c;
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].parent);
  printf("sibling = %d, ",getSibling(u));

  int deg=0;
  if(T[u].left!=NIL)deg++;
  if(T[u].right!=NIL)deg++;
  printf("degree = %d, ",deg);
  printf("depth = %d, ",D[u]);
  printf("height = %d, ",H[u]);

  if(T[u].parent==NIL)printf("root\n");
  else if(T[u].left==NIL&&T[u].right==NIL) printf("leaf\n");
  else  printf("internal node\n");
}

int main(){

  int v,l,r,root=0,i;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    T[i].parent=NIL;
  }

  for(i=0;i<n;i++){
     scanf("%d",&v);
     scanf("%d",&l);
     scanf("%d",&r);
     T[v].left=l;
     T[v].right=r;
     if(l!=NIL)T[l].parent=v;
     if(r!=NIL)T[r].parent=v;
  }

  for(i=0;i<n;i++){
    if(T[i].parent==NIL)root=i;
  }
  setDepth(root,0);
  setHeight(root);
  for(i=0;i<n;i++)print(i);
  return 0;
}
