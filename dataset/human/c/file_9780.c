#include<stdio.h>
#include<stdlib.h>
#define NIL -1

typedef struct{
  int parent;
  int left;
  int right;
}Node;



int main(){

  int n,i,j,id,child,k,r,depth;
  Node *Tree;

  scanf("%d",&n);

  Tree = malloc(sizeof(Node)*n);

  for(i = 0 ; i < n ; i++){
    Tree[i].parent = NIL;
    Tree[i].left = NIL;
    Tree[i].right = NIL;
  }

  for(i = 0 ; i < n ; i++){
    scanf("%d%d",&id,&k);

    for(j = 0 ; j < k ; j++){

      scanf("%d",&child);
      Tree[child].parent = id;

      if(j == 0)
        Tree[id].left = child;
      else if(j > 0){
        Tree[r].right = child;
      }
      r = child;
    }
  }



  for(j = 0 ; j < n ; j++){
    depth = 0;
    i = Tree[j].parent;

    while(i != NIL){
      i = Tree[i].parent;
      depth++;
    }
    if(depth == 0){
      printf("node %d: parent = %d, depth = %d, root, "
        ,j,Tree[j].parent,depth);
    }
    else if(Tree[j].left == NIL){
      printf("node %d: parent = %d, depth = %d, leaf, "
        ,j,Tree[j].parent,depth);
    }
    else{
      printf("node %d: parent = %d, depth = %d, internal node, "
        ,j,Tree[j].parent,depth);
    }

    i = Tree[j].left;
    printf("[");
      if(i != NIL){
        printf("%d",i);
      }
      while(i != NIL){ 
        i = Tree[i].right;
        if(i != -1){
          printf(", %d", i);
        }
      }
      printf("]\n");
    }
    return 0;
  }
