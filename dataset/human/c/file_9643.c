#include <stdio.h>
#define MAX 100001
 
 
typedef struct{
  int parent;
  int left;
  int right;
  int id;
}Node;
 
Node T[MAX];
 
int main(){
  int l,k,n,i,j,count=0;
  int flag=0;
  
  int id;
 
 
  for(i=0;i<MAX;i++){
    T[i].parent=-1;
    T[i].left=MAX;
    T[i].right=MAX;
    T[i].id=0;
  }
 
  scanf("%d",&n);
  
 
  for(i=0;i<n;i++){
    scanf("%d",&id);
    scanf("%d",&k);
    T[id].id=id;
    if(k!=0){
      scanf("%d",&T[id].left);
      l=T[id].left;
      T[l].parent=id;
      for(j=0;j<k-1;j++){
    scanf("%d",&T[l].right);
    l=T[l].right;
    T[l].parent=id;
 
      } 
    }
  }
 
 
 
  for(i=0;i<n;i++){
    printf("node %d:",T[i].id);
    printf(" parent = %d,",T[i].parent);
 
    j=i;
    while(T[j].parent!=-1){
      j=T[j].parent;
      count++;
    }
    printf(" depth = %d,",count);
    count=0;
 
    if(T[i].parent==-1)printf(" root,");
    else if(T[i].left!=MAX)printf(" internal node,");
    else printf(" leaf,");
 
 
    j=T[i].left;
    printf(" [");
 
 
    while(j!=MAX){
      if(flag==0)printf("%d",j);
      if(flag==1)printf("% d",j);
      j=T[j].right;
      if(j!=MAX)printf(",");
      flag=1;
    }
    printf("]");
 
 
 
    printf("\n");
      flag=0;
  }
 
 
   
 
 
  return 0;
}
