#include<stdio.h>
#include<stdlib.h>
#define MAX 100000

typedef struct{
  int parent;
  int child;
  int sibiling;
}Node;

int main(){
  Node T[MAX];
  int id,i,k,j=0,l=0,n,c;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    T[i].parent=T[i].child=T[i].sibiling=-1;
  }
  for(i=0;i!=n;i++){
    scanf("%d%d",&id,&k);
    for(j=0;j<k;j++){
      scanf("%d",&c);
      if(T[id].child==-1){
      T[id].child=c;
      }else {
	T[l].sibiling=c;
      }
      T[c].parent=id;
      l=c;
    }
  }
  for(i=0;i<n;i++){
    j=i;
    c=0;
    while(T[j].parent!=-1){
      c++;
      j=T[j].parent;
    }
    printf("node %d: parent = %d, depth = %d, ",i,T[i].parent,c);
    if(T[i].parent==-1)printf("root, [");
    else if(T[i].child!=-1)printf("internal node, [");
    else if(T[i].child==-1)printf("leaf, [");
    if(T[i].child!=-1){
      j=T[i].child;
      printf("%d",T[i].child);
      while(T[j].sibiling!=-1){
	printf(", %d",T[j].sibiling);
	j=T[j].sibiling;
      }
     
    }
     printf("]\n");
  }
  return 0;
}
