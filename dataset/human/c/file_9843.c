#include<stdio.h>
#include<stdlib.h>

typedef struct{
  int id;
  int num;
  int par;
  int *c;
}Node
;

int dep(Node *A,int i){
  if(A[i].par!=-1){
    return dep(A, A[i].par)+1;
  }
  else{
    return 0;
  }
}

int main(){
  int n,i,j,id;
  Node *A;

  scanf("%d",&n);
  A=(Node *)malloc(sizeof(Node)*n);
  for(i=0;i<n;i++){
    A[i].par=-1;
  }
  for(i=0;i<n;i++){
    scanf("%d",&id);
    scanf("%d",&A[id].num);
    A[id].id=id;
    A[id].c=(int*)malloc(sizeof(int)*A[id].num);
    for(j=0;j<A[id].num;j++){
      scanf("%d",&A[id].c[j]);
      A[A[id].c[j]].par=A[id].id;
    }
  }



  
  for(i=0;i<n;i++){
    printf("node %d: parent = %d, depth = %d, ",A[i].id,A[i].par,dep(A,A[i].id));
    if(A[i].par==-1){
      printf("root, ");
    }
    else if(A[i].num==0){
      printf("leaf, ");
    }
    else  printf("internal node, ");

    printf("[");
    for(j=0;j<A[i].num;j++){
      if(j!=0){
	printf(", ");
      }
      printf("%d",A[i].c[j]);
    }
    printf("]\n");
  }


  
  return 0;
}
