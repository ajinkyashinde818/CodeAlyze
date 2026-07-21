#include<stdio.h>
#include<stdlib.h>
typedef struct{
  int id;
  int parents;
  int left;
  int right;
}Node;
int height(Node *A,int i){
  int tmp = 0, count= 0;
  if(A[i].right!=-1){
    count = height(A,A[i].right);
  }
  if(A[i].left!=-1){
    tmp = height(A,A[i].left);
    if(tmp>count){
      count=tmp;
    }
  }
  return ++count;
}
int depth(Node *A,int id,int count){
  if(A[id].parents!=-1){
    count++;
    depth(A, A[id].parents,count);
  }
  else{
    return count;
  }
}
int main(){
  int i,j;
  int n,id,count=0,sum=0,hei;
  Node *A;
  scanf("%d",&n);
  A=(Node*)malloc(sizeof(Node)*n);
  for(i=0;i<n;i++){//parentsの初期化(-1に)
    A[i].left=-1;
    A[i].right=-1;
    A[i].parents=-1;
  }
  for(i=0;i<n;i++){//入力
    scanf("%d",&id);
    A[id].id=id;
    scanf("%d%d",&A[id].left,&A[id].right);
    A[A[id].left].parents=id;
    A[A[id].right].parents=id;
  }
  for(i=0;i<n;i++){//出力
    printf("node %d: parent = %d, ",i,A[i].parents);
    if(A[i].parents!=-1){//siblingの出力
      if(A[A[i].parents].right!=A[i].id)
	printf("sibling = %d, ",A[A[i].parents].right);
      if(A[A[i].parents].left!=A[i].id)
	printf("sibling = %d, ",A[A[i].parents].left);
    }
    else printf("sibling = -1, ");
    if(A[i].left==-1&&A[i].right==-1)//degreeの出力
      printf("degree = 0, ");
    else if(A[i].left==-1||A[i].right==-1)
      printf("degree = 1, ");
    else
      printf("degree = 2, ");
    printf("depth = %d, ",depth(A,i,count));//depthの出力
    printf("height = %d, ",height(A,i) - 1);//heightの出力
    if(A[i].parents==-1){
      printf("root");
    }else if(A[i].left==-1&&A[i].right==-1){
      printf("leaf");
    }else
      printf("internal node");
    printf("\n");
  }
  
  return 0;
}
