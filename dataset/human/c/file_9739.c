#include<stdio.h>

#define max 100001
#define nil -1

typedef struct{
  int right;
  int left;
  int parent;
}Node;

Node Tree[max];

int depth[max],length,child[max];

int main(){
  int i,own,numberchild,j;
  scanf("%d",&length);
  for(i=0;i<length;i++){
    Tree[i].parent=nil;
    Tree[i].right=nil;
    Tree[i].left=nil;
  }
  for(i=0;i<length;i++){
    scanf("%d %d",&own,&numberchild);
    for(j=0;j<numberchild;j++){
      scanf("%d",&child[j]);
      Tree[child[j]].parent=own;
      if(j == 0){
	Tree[own].left = child[0];
      }
      else{
	Tree[child[j - 1]].right = child[j];
      }
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
    int hantei=0,sub2i;
    printf("node %d: parent = %d, depth = %d, ",i,Tree[i].parent,depth[i]);
    if(Tree[i].parent==nil){
      printf("root, [");
    }
    else if(Tree[i].left==nil){
      printf("leaf, [");
    }
    else {
      printf("internal node, [");
    }
    sub2i=Tree[i].left;
    while(sub2i!=nil){
      if(hantei==0){
	printf("%d",sub2i);
      }
      else{
	printf(", %d",sub2i);
      }
      sub2i=Tree[sub2i].right;
      hantei++;
    }
    printf("]");
    if(sub2i==nil){
      printf("\n");
    }
  }
  return 0;
}
