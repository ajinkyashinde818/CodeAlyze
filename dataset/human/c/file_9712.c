#include<stdio.h>
#define NIT -1

int depth(int );
void output(int );


typedef struct{
  int parent;
  int left;
  int right;
}vertex;

int child,mae;
int degree[100000],A[100000];
vertex Tree[100000];

main(){
  
  int i,j,n,id;
  
  scanf("%d",&n);
  
  for( i=0 ; i<n ; i++){
    Tree[i].parent = Tree[i].left = Tree[i].right = NIT;
  }
  for( i=0 ; i<n ; i++){
    scanf("%d",&id);
    scanf("%d",&degree[i]);
    
    for( j=0 ; j<degree[i] ; j++){
      scanf("%d",&child);
      
      if(j == 0){
	Tree[id].left = child;
	Tree[child].parent = id;
	mae = child;
      }
      
      else {
	Tree[mae].right = child;
	Tree[child].parent = id;
	mae = child;
      }
    }
  }
  
  for( i=0 ; i<n ; i++ ){
    A[i] = depth(i);
  }
  for( i=0 ; i<n ; i++ ){
    output(i);
  }
  return 0;
}

int depth(int i){
  int d =0;
  while(1){
    if(Tree[i].parent == NIT)
      break;
    d++;
    i = Tree[i].parent;
  }
  return d;
}


void output(int i){
  
  printf("node %d: parent = %d, depth = %d, ",i,Tree[i].parent,A[i]);
  
  if(Tree[i].left == NIT && Tree[i].parent != NIT){
    printf("leaf, [");
  }
  else if(Tree[i].parent == NIT){
    printf("root, [");
  }
  else{
    printf("internal node, [");
  }
  
  if(Tree[i].left != NIT){
    while(1){
      if(Tree[Tree[i].left].right == NIT){
	printf("%d",Tree[i].left);
	break;
      }
      else {
	printf("%d, ",Tree[i].left);
	Tree[i].left = Tree[Tree[i].left].right;
      }
    }
  }
  printf("]\n");
}
