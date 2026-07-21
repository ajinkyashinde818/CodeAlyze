#include <stdio.h>
#include <string.h>
#define MAX 100000
#define NIL -1
struct Node {
  int parent;
  int left;
  int right;
};

struct Node T[MAX];

int getDepth(int u){
  int d=0;
  while(T[u].parent!=NIL){
    u=T[u].parent;
    d++;
  }
  return d;
}

void printChildren(int u,int d){
  int i,c;
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].parent);
  printf("depth = %d, ",d);
  if(T[u].parent==NIL) printf("root, ");
  else if(T[u].left==NIL) printf("leaf, ");
  else printf("internal node, ");
  printf("[");
  for(i=0,c=T[u].left;c!=NIL;i++,c=T[c].right){
    if(i) printf(", ");
    printf("%d",c);
  }
  printf("]\n");
}

int main(){
  int i,u,n;
  int d,j,c,l,v,r;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    T[i].parent=NIL;
    T[i].left=NIL;
    T[i].right=NIL;
  }
  for(i=0;i<n;i++){
    scanf("%d%d",&v,&d);
    for(j=0;j<d;j++){
      scanf("%d",&c);
      if(j==0){
	T[v].left=c;
      }
      else{
	T[l].right=c;
      }
      l=c;
      T[c].parent=v;
    }
  }
  for(i=0;i<n;i++){
    if(T[i].parent==NIL) r=i;
  }


  for(i=0;i<n;i++){
    u=getDepth(i);
    printChildren(i,u);
  }
  return 0;
}
