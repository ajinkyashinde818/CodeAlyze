#include<stdio.h>
#define MAX 100005
#define NIL -1

struct Node{
  int parent,left,right;
};
struct Node T[MAX];
int n,D[MAX];

void print(int u){
  int i,c;
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].parent);
  printf("depth = %d, ",D[u]);

  if(T[u].parent==NIL)printf("root, ");
  else if(T[u].left==NIL)printf("leaf, ");
  else printf("internal node, ");
  printf("[");
  for(i=0,c=T[u].left;c!=NIL;i++,c=T[c].right){
    if(i) printf(", ");
    printf("%d",c);
  }
  printf("]\n");
}
  /* while(c!=NIL){
    printf("%d",c);
    c=T[c].right;
    }*/

int getdepth(int u,int p){
  D[u]=p;
  if(T[u].right!=NIL) getdepth(T[u].right,p);
  if(T[u].left!=NIL) getdepth(T[u].left,p+1);
}

int main(){
  int i,v,l,r,root,d,c,j;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    T[i].parent=T[i].left=T[i].right=NIL;
  }
  for(i=0;i<n;i++){
    scanf("%d%d",&v,&d);
    for(j=0;j<d;j++){
      scanf("%d",&c);
      if(j==0){
	T[v].left=c;
      }
      else T[l].right=c;
      l=c;
      T[c].parent=v;
    }
  }
  for(i=0;i<n;i++){
    if(T[i].parent==NIL)r=i;
  }
  
  getdepth(r,0);

  for(i=0;i<n;i++) print(i);

  return 0;
}
