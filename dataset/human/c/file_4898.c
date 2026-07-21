#include<stdio.h>

#include <stdlib.h>
int main(){
  int j,a[100000][3],n,i,ndnm,parent[100000];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    parent[i]=-1;
    a[i][2]=-1;
  }
  for(i=0;i<n;i++){
    scanf("%d",&ndnm);
    scanf("%d %d",&a[ndnm][0],&a[ndnm][1]);
    if(a[ndnm][0] != -1)
     parent[a[ndnm][0]]=ndnm;
    if(a[ndnm][1] != -1)
     parent[a[ndnm][1]]=ndnm;
  }
  int ins,count=0;
  for(i=0;i<n;i++){
    if(a[i][0]==-1 && a[i][1]==-1){
      
      ins=i;
      while(ins!=-1){
	if(count > a[ins][2])
	  a[ins][2]=count;
	ins=parent[ins];
	count++;
      }
      count=0;


    }
  }
  for(i=0;i<n;i++){
    printf("node %d: parent = %d, ",i,parent[i]);
    if(parent[i] == -1)
      printf("sibling = -1, ");
    else if(a[parent[i]][0] == i)
      printf("sibling = %d, ",a[parent[i]][1]);
    else
      printf("sibling = %d, ",a[parent[i]][0]);
      
    ins=parent[i];
    while(ins!=-1){
      ins=parent[ins];
      count++;
    }
    ins=0;
    for(j=0;j<2;j++)
      if(a[i][j]!=-1)
	ins++;
    printf("degree = %d, ",ins);
    printf("depth = %d, ",count);
    printf("height = %d, ",a[i][2]);
    count=0;
    if(parent[i]==-1){
      printf("root");
    }else if(a[i][0]==-1 && a[i][1]==-1){
      printf("leaf");
    }else{
      printf("internal node");
    }
    printf("\n");
    /*
    printf("[");
    for(j=0;a[i][j]!=-1;j++){
      printf("%d",a[i][j]);
    if(a[i][j+1]!=-1)
      printf(", ");
    }
    printf("]\n");
    */ 
  }
}
