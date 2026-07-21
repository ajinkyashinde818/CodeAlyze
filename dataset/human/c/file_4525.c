#include <stdio.h>
#define MAX 100000
 
 typedef struct{
  int parent;
  int left;
  int right;
}Node;

Node Tree[MAX];

int getDepth(int i){
  int depth=0;
 
  while(Tree[i].parent!=-1){
    i=Tree[i].parent;
    depth++;
  }
  
  return depth;
}

int getSibling(int i){
  int t=Tree[i].parent;
  
  if(t==-1) return -1;
  if(Tree[t].left!=i && Tree[t].left!=-1) return Tree[t].left;
  if(Tree[t].right!=i && Tree[t].right!=-1) return Tree[t].right;
  
  return -1;
}

int getHeight(int i){
  int leftHeight=0,rightheight=0;
  
  if(Tree[i].left!=-1) leftHeight=getHeight(Tree[i].left)+1;
  if(Tree[i].right!=-1) rightheight=getHeight(Tree[i].right)+1;
  
  if(leftHeight>rightheight) return leftHeight;
  else return rightheight;
}

void print(int i){
  int degree=0;
  printf("node %d: parent = %d, ",i,Tree[i].parent);
  printf("sibling = %d, ",getSibling(i));
  
  degree = 0;
  if(Tree[i].left!=-1) degree++;
  if(Tree[i].right!=-1) degree++;
  
  printf("degree = %d, ", degree);
  printf("depth = %d, ", getDepth(i));
  printf("height = %d, ", getHeight(i));
  
  if(Tree[i].parent==-1) printf("root");
  else if(Tree[i].left==-1 && Tree[i].right==-1) printf("leaf");
  else printf("internal node");
  
  printf("\n");
}

int main(){
  
  int n,i,id,left,right,root;
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++)
    Tree[i].parent = -1;
  
  for(i=0;i<n;i++){
    scanf("%d %d %d", &id, &left, &right);
    Tree[id].left=left;
    Tree[id].right=right;
  
    if(left != -1) Tree[left].parent=id;
    if(right != -1) Tree[right].parent=id;
  }
  
  for(i=0;i<n;i++)
    if(Tree[i].parent==-1) root=i;
  
  getHeight(root);
  
  for(i=0;i<n;i++)
    print(i);
 
  return 0;
}
