#include<stdio.h>

#define MAX 25
#define ZERO -1

typedef struct Node{
  int parent;
  int left;
  int right;
  int Left;
  int Right;
}Tree;

Tree tree[MAX];

void TreePrint(int); //print関数

int TreeHeight(int,int); //heightを求める関数

int main(){

  int i,j; 
  int n;
  int id,left,right;

  scanf("%d",&n);

  for(i = 0;i < n;i++){
    tree[i].parent = tree[i].left = tree[i].right = tree[i].Left = tree[i].Right = ZERO;
  }
  for(i = 0;i < n;i++){
    scanf("%d%d%d",&id,&left,&right);

    tree[id].left = left;
    tree[right].Left = left;

    tree[id].Right = right;
    tree[left].right = right;

    tree[left].parent = id;
    tree[right].parent = id;
  }
  for(i = 0;i < n;i++){
    TreePrint(i);
  }
  return 0;
}

void TreePrint(int n){

  int i = tree[n].parent;
  int j = tree[n].Right;
  int depth = 0, degree = 0;
  int height;
  int sibling = ZERO;

  while(i != ZERO){
    i = tree[i].parent;
    depth++;
  }

  height = TreeHeight(n,0);

  if(tree[n].Left == ZERO && tree[n].right != ZERO){
    sibling = tree[n].right;
  }
  else if(tree[n].Left != ZERO && tree[n].right == ZERO){
    sibling = tree[n].Left;
  }

  if(tree[n].left == ZERO && tree[n].Right == ZERO){
    degree = 0;
  }
  else if(tree[n].left == ZERO || tree[n].Right == ZERO){
    degree = 1;
  }
  else if(tree[n].left != ZERO && tree[n].Right != ZERO){
    degree = 2;
  }

  if(depth == 0){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, root\n",n,tree[n].parent,sibling,degree,depth,height);
  }
  else if(tree[n].left == ZERO && tree[n].Right == ZERO){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, leaf\n",n,tree[n].parent,sibling,degree,depth,height);
  }
  else{
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, internal node\n",n,tree[n].parent,sibling,degree,depth,height);
  }
}

int TreeHeight(int n,int time){

  int i = time;
  int j = time;

  if(tree[n].left != ZERO){
    i = TreeHeight(tree[n].left,time+1);
  }
  if(tree[n].Right != ZERO){
    j = TreeHeight(tree[n].Right,time+1);
  }
  if(i < j){
    i = j;
  }
  return i;
}
