#include<stdio.h>
#define MAX 10000
#define NIL -1
 
typedef struct node{
  int parent,left,right;
}Node;
 
Node T[MAX];
int n,D[MAX],H[MAX];

void setDepth(int, int);
int setHeight(int);
int getSibling(int);
void print(int);
 
int main(){
  int v,l,r,i,root=0;

  scanf("%d",&n);
 
  for(i=0;i<=n-1;i++){
    T[i].parent=NIL;
  }

  for(i=0;i<=n-1;i++){
    scanf("%d %d %d",&v,&l,&r);
    T[v].left=l;
    T[v].right=r;
    if(l!=NIL){
      T[l].parent=v;
    }
    if(r!=NIL){
      T[r].parent=v;
    }
  }

  for(i=0;i<=n-1;i++){
    if(T[i].parent==NIL){
      root=i;
    }
  }

  setDepth(root,0);
  setHeight(root);
 
  for(i=0;i<=n-1;i++){
    printf("node %d: ",i);
    printf("parent = %d, ",T[i].parent);
    printf("sibling = %d, ",getSibling(i));
    int deg = 0;
    if(T[i].left!=NIL){
      deg++;
    }
    if(T[i].right!=NIL){
      deg++;
    }
    printf("degree = %d, ",deg);
    printf("depth = %d, ",D[i]);
    printf("height = %d, ",H[i]);
 
    if(T[i].parent==NIL){
      printf("root\n");
    } 
    else if(T[i].left==NIL&&T[i].right==NIL){
      printf("leaf\n");
    } 
    else {
      printf("internal node\n");
    }
  }

  return 0;
}
 
void setDepth(int u,int d){
  if(u==NIL)
    return;
  D[u]=d;
  setDepth(T[u].left,d+1);
  setDepth(T[u].right,d+1);
}
 
int setHeight(int u) {
  int h1=0, h2=0;
  if(T[u].left!=NIL)
    h1=setHeight(T[u].left)+1;
  if(T[u].right!=NIL)
    h2=setHeight(T[u].right)+1;
  return H[u]=(h1>h2 ? h1:h2);
}
 
int getSibling(int u){
  if(T[u].parent==NIL){
    return NIL;
  }
  if(T[T[u].parent].left!=u&&T[T[u].parent].left!=NIL){
    return T[T[u].parent].left;
  }
  if(T[T[u].parent].right!=u&&T[T[u].parent].right!=NIL){
    return T[T[u].parent].right;
  }
  return NIL;
}
