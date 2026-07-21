#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX 100001



typedef struct {
  int parentno;
  int depth;
  char type[20];
  int *children;
  int degree;
} node ;

node x[MAX];


int countDepth(node y, int depth){
  if(y.parentno == -1) return depth;
  return countDepth(x[y.parentno],depth+1);
}

int main(){
  int i,j,n,num,r[MAX],no;



  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    x[i].parentno=-1;
  }
  for(i=0;i<n;i++){

    scanf("%d",&no);//printf("\nDEBUG: %d\n",x[no].degree);
    scanf("%d",&x[no].degree);
    x[no].children = (int *)malloc(sizeof(int)*x[no].degree);
    for(j=0;j<x[no].degree;j++){
      scanf("%d",&x[no].children[j]);//printf("DEBUG: %d\n",x[no].children[j]);
      
      x[x[no].children[j]].parentno = no;
    }
  }
  
  for(i=0;i<n;i++){
    x[i].depth = countDepth(x[i],0);
    if(x[i].depth == 0)
      strcpy(x[i].type,"root");
    else if(x[i].degree > 0)
      strcpy(x[i].type,"internal node");
    else
      strcpy(x[i].type,"leaf");
  }
  // 出力
  for(i=0;i<n;i++){
    printf("node %d: parent = %d, depth = %d, %s, [",i,x[i].parentno,x[i].depth,x[i].type);
    //printf("\nDEBUG: %d\n",x[i].degree);
    for(j=0;j<x[i].degree;j++){
      if(j>0) printf(", ");
      printf("%d",x[i].children[j]);
    }
    printf("]\n");
  }
  
  for(i=0;i<n;i++)
    free(x[i].children);
  
  return 0;
}
