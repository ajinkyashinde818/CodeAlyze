#include <stdio.h>
#define MAX 100000
#define NIL -1

struct Node {int parent,left,right;};
struct Node T[MAX];

int n,D[MAX];

void setDepth(int,int);
void printChildren(int);


void setDepth(int u,int p){
  D[u]=p;
  if(T[u].right!=NIL)
    setDepth(T[u].right,p);
  if(T[u].left!=NIL)
    setDepth(T[u].left,p+1);
}
void printChildren(int u){
  int c,i;
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].parent);
  printf("depth = %d, ",D[u]);
  if(T[u].parent==NIL)
    printf("root, ");
  else if(T[u].left==NIL)
    printf("leaf, ");
  else
    printf("internal node, ");
  printf("[");
  c=T[u].left;
  while(c!=NIL){
    printf("%d",c);
    c=T[c].right;
    if(c!=NIL) printf(", ");
  }
  printf("]\n");
}
int main(){
  int i,j,v,d,l,c,r;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    T[i].parent=T[i].left=T[i].right=NIL;
  }
  for(i=0;i<n;i++){
    scanf("%d",&v);
    scanf("%d",&d);
    for(j=0;j<d;j++){
      scanf("%d",&c);
      if(j==0)T[v].left=c;
      else T[l].right=c;
      l=c;
      T[c].parent=v;
    }
  }
  for(i=0;i<n;i++){
    if(T[i].parent==NIL)r=i;
  }
  setDepth(r,0);
  for(i=0;i<n;i++)
    printChildren(i);
  return 0;
    }
