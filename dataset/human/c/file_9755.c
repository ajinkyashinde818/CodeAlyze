#include<stdio.h>
#define N 100000
#define node0 -1
int depth(int);
int degree(int);
 typedef struct {
  int  parent;
  int  right;
  int  left;
}tree_node;
  
tree_node tree[N];
 
int main(){
  int i,j,n;
  int id,deg,child,keep;
  scanf("%d", &n);
  for(i=0;i<n;i++){
      tree[i].parent=node0;
      tree[i].left=node0;
      tree[i].right=node0;
    }
   for(i=0; i<n; i++){
     scanf("%d",&id);
     scanf("%d",&deg);
    for(j=0;j<deg;j++){
      scanf("%d",&child);
      tree[child].parent=id;
      if(j==0){
        tree[id].left=child;
      }
      else{
        tree[keep].right=child;
      }
      keep=child;
         }
  }
    for(i=0;i<n;i++){
    printf("node %d: parent = %d, depth = %d, ",i,tree[i].parent,depth(i));
    if(tree[i].parent==node0){
      printf("root, [");
    }
    else if(tree[i].left==node0){
      printf("leaf, [");
    }
    else{
      printf("internal node, [");
    }
    degree(tree[i].left);
    printf("]\n");
  }
  return 0;
}
  
int depth(int nodeNum){
 int count = 0;
 if(tree[nodeNum].parent==node0){
     return 0;
   }
 else {
   count=depth(tree[nodeNum].parent)+1;
   return count;
   }
}
  int degree(int treeNum){
  if(treeNum==node0){
    return 0;
  }
  else {
    if(tree[treeNum].right==node0){
   printf("%d",treeNum); 
   }
  else{
    printf("%d, ",treeNum);
    degree(tree[treeNum].right);
  }
}
}
