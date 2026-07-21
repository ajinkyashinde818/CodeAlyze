#include<stdio.h>
typedef struct{
  int left,right,parent;
}node;
int main(){
  int id,n,i,j,d,t,x,c;
  node A[100000];
  scanf("%d",&n);
  for(i=0;i<n;i++)
    A[i].parent = A[i].right = A[i].left = -1;
  for(i=0;i<n;i++){
    scanf("%d %d",&id,&t);
    for(j=0;j<t;j++){
      scanf("%d",&c);
      A[c].parent = id;
      if(j == 0)A[id].left = c;
      else A[x].right = c;
      x = c;
    }
  }
  for(i=0;i<n;i++){  
    x = A[i].parent;
    d = 0;
    while(x != -1){
      x = A[x].parent;
      d++;
    }
    printf("node %d: parent = %d, depth = %d, ",i,A[i].parent,d);
    if(A[i].parent == -1)printf("root, [");
    else if(A[i].left == -1)printf("leaf, [");
    else printf("internal node, [");
    x = A[i].left;
    if(x != -1){
      printf("%d",A[i].left);
      while(A[x].right != -1){
    printf(", %d",A[x].right);
    x = A[x].right;
      }
    }
    printf("]\n");
  }
    return 0;
}
