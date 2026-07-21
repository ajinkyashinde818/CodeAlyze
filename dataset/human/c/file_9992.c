#include <stdio.h>
#define NIL -1

struct Node {int p,l,r;};
void setDepth(int ,int);
void printchildren(int);

struct Node T[100005];
int D[100005];

int main(){
  int n,i,j,r,l;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    T[i].p=T[i].l=T[i].r=NIL;
  }
  for(i=0;i<n;i++){
    int id,k,c;
    scanf("%d%d",&id,&k);
    for(j=0;j<k;j++){
      scanf("%d",&c);
      if(j==0)T[id].l=c;
      else T[l].r=c;
      l=c;
      T[c].p=id;
    }
  }
  for(i=0;i<n;i++){
    if(T[i].p==NIL)r=i;
  }
  setDepth(r,0);
  for(i=0;i<n;i++){
    printchildren(i);
  }
  return 0;
}

void setDepth(int u, int p){
  D[u]=p; // Depth Array
  if(T[u].r != NIL)setDepth(T[u].r,p);
  if(T[u].l != NIL)setDepth(T[u].l,p+1);
}

void  printchildren(int u){
  int c=T[u].l,i;

  printf("node %d: ",u);
  printf("parent = %d, ",T[u].p);
  printf("depth = %d, ",D[u]);
  if(T[u].p==NIL)printf("root, ");
  else if(T[u].l==NIL)printf("leaf, ");
  else printf("internal node, ");

  printf("[");
  for(i=0,c=T[u].l;c!=NIL;i++,c=T[c].r){
    if(i)printf(", ");
    printf("%d",c);
  }
  printf("]\n");
}
