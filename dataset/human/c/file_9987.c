#include <stdio.h>
#define N 100000
#define NIL -1
struct Node{
  int parent;
  int right;
  int left;
};
struct Node Tree[N];
int n,D[N];
int getDepth(int a){
  int dep=0;
  while(Tree[a].parent!=-1){
    a=Tree[a].parent;
    dep++;
  }
  return dep;
}
void print(int x){
  int i,j;
  printf("node %d: parent = %d, depth = %d, ",x,Tree[x].parent,D[x]);
  if(Tree[x].parent==-1) printf("root, ");
  else if(Tree[x].left==-1) printf("leaf, ");
  else printf("internal node, ");
  printf("[");
  for(i=0,j=Tree[x].left;j!=NIL;i++,j=Tree[j].right){
    if(i) printf(", ");
    printf("%d",j);
  }
  printf("]\n");
}
int main(){
  int a,b,i,j,l,m;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    Tree[i].parent=NIL;
    Tree[i].left=NIL;
    Tree[i].right=NIL;
  }
  for(i=0;i<n;i++){
    scanf("%d%d",&l,&m);
    for(j=0;j<m;j++){
      scanf("%d",&a);
      if(j==0)Tree[l].left=a;
      else Tree[b].right=a;
      b=a;
      Tree[a].parent=l;
    }
  }
  for(i=0;i<n;i++){
    D[i]=getDepth(i);
  }
  for(i=0;i<n;i++){
    print(i);
  }
  return 0;
}
