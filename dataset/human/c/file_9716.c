#include<stdio.h>
#define MAX 100005
#define NIL -1

void Print(int);
int depth(int, int);

struct Node{
  int parent, left, right;
};

struct Node Tree[MAX];

int Depth[MAX];

int main(){
  int n,i,j,num,dep,c,l,key;

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++){
    Tree[i].parent = Tree[i].left = Tree[i].right = NIL;
  }
  for(i = 0 ; i < n ; i++){
    scanf("%d%d",&num,&dep);
    for(j = 0 ; j < dep ; j++){
      scanf("%d",&c);
      if(j == 0) Tree[num].left = c;
      else Tree[l].right = c;
      l = c;
      Tree[c].parent = num;
    }
  }
  
  for(i = 0 ; i < n ; i++){
    if(Tree[i].parent == NIL) key = i;
  }

  depth(key,0);
 
  for(i = 0 ; i < n ; i++) Print(i);
  
  return 0;
}

void Print(int x){
  int i,y;

  printf("node %d: ",x);
  printf("parent = %d, ",Tree[x].parent);
  printf("depth = %d, ",Depth[x]);

  if(Tree[x].parent == NIL) printf("root, ");
  else if(Tree[x].left == NIL) printf("leaf, ");
  else printf("internal node, ");

  printf("[");

  for(i = 0, y = Tree[x].left ; y != NIL ; i++, y = Tree[y].right){
    if(i > 0) printf(", ");
    printf("%d",y);
  }
  printf("]\n");
}

int depth(int x, int y){
  Depth[x] = y;
  if(Tree[x].right != NIL) depth(Tree[x].right, y);
  if(Tree[x].left != NIL) depth(Tree[x].left ,y+1);
}
