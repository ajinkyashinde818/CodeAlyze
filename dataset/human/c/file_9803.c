#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int parent;
  int left;
  int right;
} node;

int main(){
  node *ro,*A;
  int i,j,n,r,c,k,a,depth;

  scanf("%d",&n);
  ro=(node *)malloc(sizeof(node)*n);
  A=ro;
  for(i=0;i<n;i++){
    A[i].parent=-1;
    A[i].left=-1;
    A[i].right=-1;
  }
  for(i=0;i<n;i++){
    scanf("%d %d",&r,&k);    
    for(j=0;j<k;j++){
      scanf("%d",&c);
      A[c].parent=r;
      if(j==0)A[r].left=c;
      else A[a].right=c;
      a=c;
    }
  }
  for(i=0;i<n;i++){
    a=A[i].parent;
    depth=0;
    while(a!=-1){
      depth++;
      a=A[a].parent;
    }
    printf("node %d: parent = %d, depth = %d, ",i,A[i].parent,depth);
    if(A[i].parent==-1)printf("root, [");
    else if(A[i].left==-1)printf("leaf, [");
    else printf("internal node, [");
    a=A[i].left;
    if(a!=-1){
      printf("%d",A[i].left);
      while(A[a].right!=-1){
	printf(", %d",A[a].right);
	a=A[a].right;
      }
    }
    printf("]\n");
  }
  return 0;
}
