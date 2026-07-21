#include<stdio.h>
#include<stdlib.h>

typedef struct{
  int parent;
  int left;
  int right;
}Node;

void print(int);
int sibling(int);
int height(int);
int degree(int);

Node Tree[25];
int H[25];


int main(){

  int n,i,j,id,child,r,depth;
 
  scanf("%d",&n);

  for(i = 0 ; i < n ; i++){
    Tree[i].parent = -1;
    Tree[i].left = -1;
    Tree[i].right = -1;
  }

  for(i = 0 ; i < n ; i++){
    scanf("%d",&id);

    for(j = 0 ; j < 2 ; j++){

      scanf("%d",&child);
      Tree[child].parent = id;

      if(j == 0)
	Tree[id].left = child;
      else if(j == 1){
	Tree[id].right = child;
      }
      r = child;
    }
  }
  
  for(j = 0 ; j < n ; j++) print(j);
 
  return 0; 
}


void print(int j){
  
  int depth,i,s,deg,h;

  depth = 0;
  
  i = Tree[j].parent;
  
  while(i != -1){
    i = Tree[i].parent;
    depth++;
  }

  h = height(j);
  s = sibling(j);
  deg = degree(j);

  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", j,Tree[j].parent, s, deg, depth, h);

  if(Tree[j].parent == -1) printf("root\n");
  else if(Tree[j].left==-1 && Tree[j].right==-1) printf("leaf\n");
  else printf("internal node\n");
}


int height(int s){
  int r, l;
  r = l = 0;

  if(Tree[s].left == -1 && Tree[s].right == -1) return 0;

  if(Tree[s].left != -1 && Tree[s].right != -1){
    l = height(Tree[s].left) + 1;
    r = height(Tree[s].right) + 1;
    if(l < r) return r;
    else return l;  
  }
  else if(Tree[s].left == -1 && Tree[s].right != -1) return height(Tree[s].right) +1;
  else if(Tree[s].right == -1 && Tree[s].left != -1) return height(Tree[s].left) +1;

}

int sibling(int s){
  if( Tree[s].parent == -1 )return -1;
  if( Tree[Tree[s].parent].left != -1 && Tree[Tree[s].parent].left != s ){
    return Tree[Tree[s].parent].left;
  }
  if( Tree[Tree[s].parent].right != -1 && Tree[Tree[s].parent].right != s ){
    return Tree[Tree[s].parent].right;
  }
  return -1;
}

int degree(int s){
  int d = 0;

  if(Tree[s].left != -1) d++;
  if(Tree[s].right != -1) d++;

  return d;

}
