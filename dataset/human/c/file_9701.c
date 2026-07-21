#include<stdio.h>
#define MAX 100001
#define ZERO -1
 
typedef struct Node{
  int parent; 
  int left,right;
}Tree;
 
Tree tree[MAX];
 
void Treeprint(int);
 
int main(){
  int n,i,j,id,k,child,l;
 
  scanf("%d", &n);
 
  for(i = 0;i < n;i++){
    tree[i].parent = tree[i].left = tree[i].right = ZERO;
  }
   
    for(i = 0;i < n;i++){
      scanf("%d%d",&id,&k);
     
      for(j = 0;j < k;j++){
        scanf("%d",&child); 
        tree[child].parent = id; 
 
        if(j == 0){
          tree[id].left = child;
        }
        else if(j > 0){
          tree[l].right = child;
        }
        l = child;
      }
    }
    for(i = 0;i < n;i++){
      Treeprint(i);
    }
    return 0;
  }
 
  void Treeprint(int n){ 
    int i = tree[n].parent;
    int depth = 0;
    while(i != ZERO){
      i = tree[i].parent;
      depth++;
    }
    if(depth == 0){
      printf("node %d: parent = %d, depth = %d, root, ",n,tree[n].parent,depth);
    }
    else if(tree[n].left == ZERO){
      printf("node %d: parent = %d, depth = %d, leaf, ",n,tree[n].parent,depth);
    }
    else{
      printf("node %d: parent = %d, depth = %d, internal node, ",n,tree[n].parent,depth);
    }
 
    i = tree[n].left;
    printf("[");
    if(i != ZERO){
      printf("%d",i);
    }
    while(i != ZERO){ 
      i = tree[i].right;
 
      if(i != ZERO){
        printf(", %d", i);
      }
    }
    printf("]\n");
  }
