#include<stdio.h>

#define max 100001
#define nil -1

typedef struct{
  int right;
  int left;
  int parent;
}Node;

int height(int);
Node Tree[max],tmp;

int depth[max],length,child[max],sibling[max],degree[max];

int main(){
  int i,own,numberchild,j;
  scanf("%d",&length);
  for(i=0;i<length;i++){
    Tree[i].parent=nil;
    Tree[i].right=nil;
    Tree[i].left=nil;
  }
  for(i=0;i<length;i++){
    scanf("%d",&own);
    for(j=0;j<2;j++){
      scanf("%d",&child[j]);
      Tree[child[j]].parent=own;
      Tree[own].left = child[0];
      Tree[own].right = child[1];
    }
  }
  
  for(i=0;i<length;i++){
    int count=0,subi;
    subi=i;
    while(1){
      if(Tree[subi].parent==nil){
	break;
      }
      subi=Tree[subi].parent;
      count++;
    }
    depth[i]=count;
  }

  for(i=0;i<length;i++){
    if(depth[i]==0){
      sibling[i]=nil;
    }
    else if(Tree[Tree[i].parent].left==i){
	sibling[i]=Tree[Tree[i].parent].right;
      }
      else{
	sibling[i]=Tree[Tree[i].parent].left;
      }
    }

  int Dcount;
  for(i=0;i<length;i++){
    Dcount=0;
    if(Tree[i].right!=nil){
      Dcount++;
    }
    if(Tree[i].left!=nil){
      Dcount++;
    }
    degree[i]=Dcount;
    }
  
  for(i=0;i<length;i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,Tree[i].parent,sibling[i],degree[i],depth[i],height(i));
    if(Tree[i].parent==nil){
      printf("root\n");
    }
    else if(Tree[i].left==nil && Tree[i].right!=nil || Tree[i].left!=nil && Tree[i].right==nil){
      printf("internal node\n");
    }
    else if(Tree[i].left!=nil && Tree[i].right!=nil){
      printf("internal node\n");
      }
    else {
      printf("leaf\n");
    }
  }

  return 0;
}

int height(int u){
    int HL=0,HR=0;
    if(Tree[u].left!=nil){
      HL=height(Tree[u].left)+1;
    }
    if(Tree[u].right!=nil){
      HR=height(Tree[u].right)+1;
    }
    if(HL<HR){
      return HR;
    }
    else{
      return HL;
    }
  }
