#include<stdio.h>
#include<stdlib.h>


#define MAX 100001
typedef struct node{
  int parent;
  int left;
  int right;
} Tree;

int main(){
  int n,i,j,id,k,child,right=0,parent,d;
  Tree T[MAX];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    T[i].parent=-1;
    T[i].left=-1;
    T[i].right=-1;
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&id,&k);

    for(j=0;j<k;j++){
      scanf("%d",&child);
      T[child].parent=id;

      if(j==0){
    T[id].left=child;
      }else{
    T[right].right=child;
      }

      right=child;
    }
  }

  for(i=0;i<n;i++){
    d=0;
    parent=T[i].parent;

    while(parent!=-1){
      parent=T[parent].parent;
      d++;
    }

    if(d==0){
      printf("node %d: parent = -1, depth = 0, root, [",i);
    }else if(T[i].left==-1){
      printf("node %d: parent = %d, depth = %d, leaf, [",i,T[i].parent,d);
    }else{
      printf("node %d: parent = %d, depth = %d, internal node, [",i,T[i].parent,d);
    }

    parent=T[i].left;

    if(parent!=-1){
      printf("%d",parent);
    }

    while(parent!=-1){
      parent=T[parent].right;

      if(parent!=-1){
    printf(", %d",parent);
      }
    }

    printf("]\n");
  }

  return 0;
}
