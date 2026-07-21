#include<stdio.h>
#define NIL -1

int depth(int);
int sibling(int);
int height(int);
void output(int);


typedef struct{
  int parent;
  int left;
  int right;
}vertex;

int D[25];
int ver[25];
vertex Tree[25];

int main(){
  
  int i,n,l,r;
  
  scanf("%d",&n);
  
  for( i=0 ; i<n ; i++){
    Tree[i].parent = Tree[i].left = Tree[i].right = NIL;
  }
  for( i=0 ; i<n ; i++){
    scanf("%d",&ver[i]);
    
    if(i == 0){
      Tree[ ver[i] ] .parent= NIL;
    }

    scanf("%d",&Tree[ver[i]].left);
    scanf("%d",&Tree[ver[i]].right);
    
    l = Tree[ver[i]].left;
    r = Tree[ver[i]].right;
    Tree[l].parent = Tree[r].parent = ver[i];
  }

  for( i=0 ; i<n ; i++){
    D[i] = depth(i);
  }
  for( i=0 ; i<n ; i++){
    output(i);
  }
 
  return 0;
}

int depth(int i){
  int d =0;
  while(1){
    if(Tree[i].parent == NIL) break;
    d++;
    i = Tree[i].parent;
  }
  return d;
}

int height(int i){
  int RightHeight=0,LeftHeight=0;
  
  if( Tree[i].left == NIL && Tree[i].right == NIL )return 0;
  if(Tree[i].left!=NIL)LeftHeight = height(Tree[i].left)+1;
  if(Tree[i].right!=NIL)RightHeight = height(Tree[i].right)+1;
  
  if(RightHeight>LeftHeight)return RightHeight;
  else return LeftHeight;
} 

int sibling(int i){
  int s;
  s = Tree[i].parent;
  if( s == -1)return NIL;
  if( i == Tree[s].left)return Tree[s].right;
  else if(i == Tree[s].right)return Tree[s].left;
  else if( Tree[s].right == NIL && Tree[s].left == NIL)return NIL;
}

void output(int i){
  //int d;
  
  printf("node %d: parent = %d, sibling = %d, degree = ",i,Tree[i].parent,sibling(i));
  if(Tree[i].left ==NIL && Tree[i].right ==NIL)printf("0, ");
  else if(Tree[i].left == NIL || Tree[i].right == NIL)printf("1, ");
  else printf("2, ");
 
  printf("depth = %d, height = %d, ",D[i],height(i));
 
  if(Tree[i].left == NIL && Tree[i].right == NIL && Tree[i].parent!=NIL)printf("leaf\n");
  else if(Tree[i].parent == NIL)printf("root\n");
  else printf("internal node\n");
}
