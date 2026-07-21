#include<stdio.h>
#define MAX 100000

 struct Node{
  int parent;
  int left;
  int right;
};
 
struct Node Three[MAX];
 
int getDepth(int num){
  int depth = 0;
 
  for(depth = 0; Three[num].parent != -1; depth++){
    num = Three[num].parent;
  }
return depth;
}
 
int main(){
  int i,j,n;
  int num,deg,child,k = 0;
 
  scanf("%d",&n);
 
  for(i=0;i<n;i++){
    Three[i].parent = -1;
    Three[i].left = -1;
    Three[i].right = -1;
  }
 
  for(i=0;i<n;i++){
    scanf("%d%d",&num,&deg);
 
    for(j=0;j<deg;j++){
      scanf("%d",&child);
      if(j==0) Three[num].left=child;
      else Three[k].right=child;
      k=child;
      Three[child].parent=num;
    }
  }
 
  for(i = 0; i < n; i++){
    printf("node %d: parent = %d, depth = %d",i,Three[i].parent,getDepth(i));
 
    if(getDepth(i) == 0){
      printf(", root, [");
    }
    else if(Three[i].left == -1){
      printf(", leaf, [");
    }
    else{
      printf(", internal node, [");
    }
 
    j=Three[i].left;
 
    while(j != -1){
      printf("%d", j);
      j = Three[j].right;
 
      if(j != -1){
    printf(", ");
      }
    }
    printf("]\n");
  }
 
  return 0;
}
