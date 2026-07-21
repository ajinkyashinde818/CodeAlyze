#include <stdio.h>
#define N 100000
#define NIL -1
struct Node {
  int parent;
  int left;
  int right;
};
struct Node T[N];
int D[N];


void getDepth(int x,int y){
  D[x]=y;
  if(T[x].right != NIL)
    getDepth(T[x].right,y);
  if(T[x].left != NIL)
    getDepth(T[x].left,y+1);
}



int main(){
  int a,n,i,j,x;
  int id,ks,y,z;

  for(i=0;i<N;i++){
    T[i].parent=NIL;
    T[i].left=NIL;
    T[i].right=NIL;    
  }
    
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d%d",&id,&ks);
    for(j=0;j<ks;j++){
      scanf("%d",&y);
      if(j==0){
	T[id].left=y;
      }
      else{
	T[x].right=y;
      }
      x=y;
      T[y].parent=id;
    }
  }
  for(i=0;i<n;i++){
    if(T[i].parent==NIL)
      z=i;
  }
  
  getDepth(z,0);
  
  for(i=0;i<n;i++){
    printf("node %d: parent = %d, depth = %d, ",i,T[i].parent,D[i]);
    if(T[i].parent==NIL)
      printf("root, [");
    else if(T[i].left==NIL)
      printf("leaf, [");
    else
      printf("internal node, [");

    for(j=0,a=T[i].left;a!=NIL;j++,a=T[a].right){
      if(j)
	printf(", ");
      printf("%d",a);
    }
    printf("]\n");
  }

  return 0;
}
