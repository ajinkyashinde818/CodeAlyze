#include<stdio.h>
#include<stdlib.h>

typedef struct{
  int parent;
  int leftch;
  int rightsib;
}Node;



int main(){

  int n,i,j,id,child,k,r,depth;
  Node *Tree;

  scanf("%d",&n);

  Tree = malloc(sizeof(Node)*n);

  for(i = 0 ; i < n ; i++){
    Tree[i].parent = -1;
    Tree[i].leftch = -1;
    Tree[i].rightsib = -1;
  }

  for(i = 0 ; i < n ; i++){
    scanf("%d%d",&id,&k);

    for(j = 0 ; j < k ; j++){

      scanf("%d",&child);
      Tree[child].parent = id;

      if(j == 0)
	Tree[id].leftch = child;
 else if(j > 0){
          Tree[r].rightsib = child;
        }
        r = child;
      }
    }
  
  

    for(j = 0 ; j < n ; j++){

      depth = 0;

      i = Tree[j].parent;

    while(i != -1){
      i = Tree[i].parent;
      depth++;
    }
    if(depth == 0){
      printf("node %d: parent = %d, depth = %d, root, ",j,Tree[j].parent,depth);
    }
    else if(Tree[j].leftch == -1){
      printf("node %d: parent = %d, depth = %d, leaf, ",j,Tree[j].parent,depth);
    }
    else{
      printf("node %d: parent = %d, depth = %d, internal node, ",j,Tree[j].parent,depth);
    }
  
    i = Tree[j].leftch;
    printf("[");
    if(i != -1){
      printf("%d",i);
    }
    while(i != -1){ 
      i = Tree[i].rightsib;
      
      if(i != -1){
        printf(", %d", i);
      }
    }
    printf("]\n");
    }
    return 0;
}
